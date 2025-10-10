# Internet of Things (IoT) Projects with ESP32

![ESP32 IoT Banner](https://via.placeholder.com/800x200/007ACC/FFFFFF?text=ESP32+IoT+Projects) <!-- Replace with an actual image if available -->

## 📖 Overview

Welcome to the **Internet of Things (IoT) Projects** repository! This collection showcases hands-on experiments and prototypes built using the **ESP32 microcontroller**, a versatile platform for IoT development. The projects focus on embedded systems, sensor integration, and interactive mini-games, demonstrating practical applications of IoT concepts like hardware interfacing, wireless communication, and real-time user interaction.

Currently, this repo features two engaging **Dino Game clones** inspired by the classic Google Chrome offline game—one using a TFT display and the other with an OLED display. These projects highlight display rendering, button inputs, and audio feedback in an IoT context.

Future expansions may include sensor-based prototypes (e.g., temperature monitoring, motion detection) and more advanced IoT setups with Wi-Fi connectivity.

### Key Features
- **ESP32-Centric**: Leverages the power-efficient ESP32 for low-cost IoT solutions.
- **Interactive Prototypes**: Combines hardware (displays, buttons, buzzers) with software for engaging demos.
- **Modular Design**: Each project is self-contained with setup guides and dependencies.
- **Educational Focus**: Ideal for beginners learning embedded programming, IoT fundamentals, and Arduino-style development.

## 📌 Projects

### 1. **Dino Game with TFT Display**
   - **Description**: A vibrant clone of the Dino game running on a 240x320 TFT display. Features smooth graphics, jumping mechanics, random obstacles, and a scoring system.
   - **Tech Stack**: ESP32 + TFT_eSPI library for high-resolution rendering.
   - **Hardware**: ESP32 DevKit, 240x320 TFT Display (ILI9341-compatible), jumper wires.
   - **Demo**: [View Project Folder](DinoGame-TFT)
   - **Use Case**: Demonstrates graphical IoT interfaces for gaming or visualization dashboards.

### 2. **Dino Game with OLED Display**
   - **Description**: A compact version of the Dino game on a 128x64 OLED screen, with button-controlled jumps and optional buzzer sound effects for collisions/scores.
   - **Tech Stack**: ESP32 + Adafruit SSD1306 & GFX libraries for monochrome graphics.
   - **Hardware**: ESP32 DevKit, 128x64 OLED Display (SSD1306, I2C), push button, buzzer (optional).
   - **Demo**: [View Project Folder](DinoGame-OLED)
   - **Use Case**: Explores low-power displays in battery-operated IoT devices like wearables or sensors.

## 🚀 Getting Started

To run these projects, you'll need basic hardware and the Arduino IDE or PlatformIO.

### Prerequisites
- **Hardware**:
  - ESP32 Development Board (e.g., ESP32-WROOM-32).
  - Displays and peripherals as listed per project.
  - USB cable for flashing.
- **Software**:
  - [Arduino IDE](https://www.arduino.cc/en/software) (v2.0+) or [PlatformIO](https://platformio.org/).
  - ESP32 board support package (install via Boards Manager).
- **Libraries** (install via Library Manager):
  - TFT_eSPI (for TFT project).
  - Adafruit SSD1306 & Adafruit GFX Library (for OLED project).

### Setup Instructions
1. **Clone the Repository**:
   ```
   git clone https://github.com/ahmedelkerdawy/Internet_of-things_IOT.git
   cd Internet_of-things_IOT
   ```

2. **Open a Project**:
   - Navigate to `DinoGame-TFT` or `DinoGame-OLED`.
   - Open the `.ino` file in Arduino IDE or the project in PlatformIO.

3. **Configure Hardware**:
   - Wire components (see wiring diagrams in each project's README).
   - For TFT: Edit `User_Setup.h` in TFT_eSPI library to match your display pins.

4. **Upload Code**:
   - Select ESP32 board and port.
   - Build and upload the firmware.
   - Power on and play!

### Example Wiring (OLED Project)
| Component | ESP32 Pin | Notes |
|-----------|-----------|-------|
| OLED SDA  | GPIO21   | I2C Data |
| OLED SCL  | GPIO22   | I2C Clock |
| Button    | GPIO4    | Pull-up resistor recommended |
| Buzzer    | GPIO5    | Active buzzer for beeps |

## 🛠 Tools & Technologies

- **Microcontroller**: ESP32 (Wi-Fi & Bluetooth enabled for future IoT expansions).
- **Displays**: ILI9341 TFT (color, high-res) & SSD1306 OLED (monochrome, low-power).
- **Libraries**:
  - TFT_eSPI: Fast TFT graphics.
  - Adafruit SSD1306/GFX: OLED rendering and fonts.
- **Development Environment**: Arduino IDE / PlatformIO.
- **IoT Concepts Covered**: GPIO control, I2C communication, interrupt-based inputs, timing loops.

## 🤝 Contributing

Contributions are welcome! Whether it's adding new projects, fixing bugs, or improving docs:
1. Fork the repo.
2. Create a feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.

Please follow the [Contributor Covenant Code of Conduct](CODE_OF_CONDUCT.md) if one is added.

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Inspired by the endless runner genre and ESP32 community projects.
- Thanks to Adafruit and Bodmer (TFT_eSPI) for open-source libraries.

---

**Connect with the Author**: [Ahmed El-Kerdawy](https://github.com/ahmedelkerdawy) | Questions? Open an issue!

*Last Updated: October 10, 2025*
