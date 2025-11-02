# ESP32 IoT Sensor Node with MQTT and WiFi Manager

This project demonstrates an **IoT Sensor Node** built using **ESP32**, which publishes sensor data (temperature and hall sensor readings) to an **MQTT broker** and can be remotely controlled via MQTT topics.  
It uses **WiFiManager** for easy WiFi configuration and **PubSubClient** for MQTT communication.

## 🚀 Features

- 📶 **WiFi Auto-Configuration** using WiFiManager (no hardcoded SSID or password)
- 🔁 **Automatic Reconnection** to WiFi and MQTT broker
- 🌡️ **Internal Temperature Sensor Reading**
- 🧲 **Hall Effect Sensor Reading**
- 💡 **Remote LED Control** via MQTT commands (`ON` / `OFF`)
- 🧠 **Smart Reset Button** to clear saved WiFi credentials
---
## 🛠️ Hardware Requirements

- **ESP32 Development Board**
- **LED** connected to GPIO 2 (built-in LED can also be used)
- **Push Button** connected to GPIO 0 for WiFi reset

---

## 🧩 Software Dependencies

The project uses **PlatformIO** for building and uploading code.

### Libraries:
- `WiFi.h`
- `WiFiManager`  
- `PubSubClient`

You can install these from the **PlatformIO Library Manager** or add them to your `platformio.ini` file.

---

## ⚙️ MQTT Configuration

Update the following lines in your `main.cpp` with your MQTT broker details:

```cpp
const char* mqtt_server = "YOUR_MQTT_BROKER_IP";
const int mqtt_port = 1883;
```
---
📡 MQTT Topics
Topic	Direction	Description	Example Payload
esp32/temperature	Publish	Temperature in °C	28.5
esp32/hall	Publish	Hall sensor raw value	63
esp32/led	Subscribe	Control onboard LED	ON / OFF
## 📂 Folder Structure
ESP32_IoT_Sensor_Node_MQTT_WiFi_Manager/
├── src/ # Source code (main.cpp)
├── include/ # Header files
├── lib/ # Libraries
├── test/ # Test files
├── platformio.ini # PlatformIO configuration
└── README.md # This file
🧾 How to Use

Flash the code to your ESP32 using PlatformIO.

On first boot, ESP32 will create a WiFi Access Point:

SSID: ESP32_Config_AP

Password: 12345678

Connect your phone/laptop to that AP.

Configure your WiFi network via the captive portal.

Once connected, ESP32 will automatically connect to WiFi and start sending data to your MQTT broker.

Use any MQTT client (like MQTT Explorer or HiveMQ Web Client) to monitor and control the ESP32.

🔁 Reset WiFi Credentials

Hold the button connected to GPIO 0 for 3 seconds to clear saved WiFi settings.
The ESP32 will reboot and create the configuration access point again.
## 🚀 Getting Started
1. Open the project in **PlatformIO (VSCode)**  
2. Configure WiFi and MQTT credentials in the code  
3. Build and upload to the ESP32  

## 🧠 Author
**Ahmed Elkerdawy**  
[GitHub](https://github.com/ahmedelkerdawy)


---

### ✅ Next Steps

Run these commands to add and push the README to GitHub:
```bash
cd /home/ahmed/Documents/Iot/05_platformio/ESP32_ IoT_ Sensor_ Node_ with_ MQTT_ and_ WiFi_ Manager
nano README.md
# (paste the text above, then save with CTRL+O, CTRL+X)

git add README.md
git commit -m "Add README for ESP32 IoT Sensor Node project"
git push

