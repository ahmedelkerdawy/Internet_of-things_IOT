/*
  Final ESP32 sketch that connects to Wi-Fi and MQTT broker

  - Uses WiFiManager for easy setup (AP config portal)
  - Falls back to manual connect to a hidden SSID if needed
  - Publishes temperature & hall values to HiveMQ (broker.hivemq.com)
  - Subscribes to esp32/led to control onboard LED
  - Reset button clears WiFi settings when held for 3 seconds
*/

#include <WiFi.h>
#include <WiFiManager.h>  
#include <PubSubClient.h>  

// ====== Pins ======
#define LED_PIN 2             // Onboard LED 
#define RESET_BUTTON_PIN 0    // Boot button on many dev boards (active LOW)


// ====== Hidden network ======
const char* HIDDEN_SSID     = "Ahmed Elkerdawy";    
const char* HIDDEN_PASSWORD = "Ahmed Elkerdawy 20301";     

// ====== MQTT (HiveMQ public) ======
const char* mqtt_server = "broker.hivemq.com";
const int   mqtt_port   = 1883;

const char* temp_topic = "esp32/temperature";
const char* hall_topic = "esp32/hall";
const char* led_topic  = "esp32/led";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;

// Forward declarations for ESP32 internal functions
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read(); // builtin temperature sensor (returns raw)
#ifdef __cplusplus
}
#endif

// ====== MQTT message callback ======
void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("MQTT message arrived [");
  Serial.print(topic);
  Serial.print("]: ");

  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  Serial.println(msg);

  // LED control: accept "ON"/"OFF" or "true"/"false"
  if (strcmp(topic, led_topic) == 0) {
    if (msg == "ON" || msg == "true") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED -> ON");
    } else if (msg == "OFF" || msg == "false") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED -> OFF");
    } else {
      Serial.println("LED: unknown payload");
    }
  }
}

// ====== MQTT reconnect helper ======
void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker... ");
    // create a random client ID to avoid collisions
    String clientId = "ESP32-" + String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe(led_topic);
      Serial.print("Subscribed to: ");
      Serial.println(led_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" — retrying in 5s");
      delay(5000);
    }
  }
}

// ====== Try to connect to a hidden SSID (manual fallback) ======
bool connectHiddenNetwork(const char* ssid, const char* password, uint32_t timeout_ms = 20000) {
  if (!ssid || strlen(ssid) == 0) {
    Serial.println("Hidden SSID not provided, skipping manual connect.");
    return false;
  }

  Serial.print("Attempting manual connect to hidden SSID: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);          // station mode
  WiFi.begin(ssid, password);   // attempt to connect (works for hidden SSIDs if credentials are correct)

  uint32_t start = millis();
  while (millis() - start < timeout_ms) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\n➡️ Connected to hidden network!");
      Serial.print("IP Address: ");
      Serial.println(WiFi.localIP());
      return true;
    }
    Serial.print(".");
    delay(500);
  }

  Serial.println("\n❌ Manual connect to hidden SSID failed (timeout).");
  return false;
}

// ====== Reset button handler (clear WiFi) ======
void checkResetButton() {
  // active LOW
  if (digitalRead(RESET_BUTTON_PIN) == LOW) {
    Serial.println("Reset button pressed. Hold 3 seconds to clear WiFi settings...");
    delay(3000);
    if (digitalRead(RESET_BUTTON_PIN) == LOW) {
      Serial.println("Clearing WiFi settings and restarting...");
      WiFiManager wm;
      wm.resetSettings(); // clear saved WiFi credentials
      delay(500);
      ESP.restart();
    } else {
      Serial.println("Reset cancelled.");
    }
  }
}

// ====== Setup ======
void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);

  Serial.println("\n=== ESP32 Start ===");

  // Try WiFiManager first (gives you a web portal to configure SSID/password)
  WiFiManager wm;
  // Optional: set timeout for autoConnect (ms). If you want to try manual fallback quickly, set short timeout.
  const unsigned long wmTimeoutMs = 20000; // 20 seconds
  wm.setConfigPortalTimeout(wmTimeoutMs / 1000); // seconds

  Serial.println("Trying WiFiManager autoConnect (AP portal)...");
  // This call will attempt to connect using saved credentials.
  // If it can't, it starts an AP where you can configure network.
  if (wm.autoConnect("ESP32_Config_AP", "12345678")) {
    Serial.println("WiFiManager connected using saved credentials or portal input.");
    Serial.print("Connected SSID: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    // autoConnect returned false (timeout or failed). Try manual connection to hidden SSID if provided.
    Serial.println("WiFiManager autoConnect failed or timed out.");
    if (!connectHiddenNetwork(HIDDEN_SSID, HIDDEN_PASSWORD)) {
      Serial.println("Could not connect to Wi-Fi. Device will keep retrying.");
      // You can either restart to try again or keep running and attempt reconnects in loop.
    }
  }

  // Setup MQTT client
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqtt_callback);

  // Small indicator: turn LED ON if we have WiFi now
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_PIN, HIGH);
  }
}

// ====== Main loop ======
void loop() {
  checkResetButton();

  // Ensure WiFi is connected; if not, try a quick reconnect (manual attempt if hidden credentials exist)
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected, attempting reconnect...");
    // Try a short reconnect using saved WiFi stack
    WiFi.reconnect();
    uint32_t start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 5000) {
      delay(200);
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("WiFi reconnected.");
      digitalWrite(LED_PIN, HIGH);
    } else {
      // Try manual hidden SSID connect as a fallback
      connectHiddenNetwork(HIDDEN_SSID, HIDDEN_PASSWORD, 10000);
    }
  }

  // Ensure MQTT connection
  if (WiFi.status() == WL_CONNECTED) {
    if (!client.connected()) {
      reconnect_mqtt();
    }
    client.loop();
  }

  // Publish periodically (every 5 seconds)
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    if (WiFi.status() == WL_CONNECTED && client.connected()) {
      // Read internal temperature sensor (ESP32 returns a value in some units; convert roughly)
      float temp_c = (temprature_sens_read() - 32) / 1.8; // approximate conversion (works in many sketches)
      char tempBuf[16];
      dtostrf(temp_c, 5, 2, tempBuf);
      client.publish(temp_topic, tempBuf);
      Serial.print("Published temperature: ");
      Serial.println(tempBuf);

      // Read hall sensor
      int hall_val = hallRead();
      char hallBuf[16];
      itoa(hall_val, hallBuf, 10);
      client.publish(hall_topic, hallBuf);
      Serial.print("Published hall: ");
      Serial.println(hallBuf);
    } else {
      Serial.println("Skipping publish (no WiFi/MQTT).");
    }
  }
}
