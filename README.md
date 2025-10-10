# Internet of Things (IoT) Projects

This repository contains different **ESP32-based IoT projects**.  
Currently, it includes two mini-games inspired by the Google Chrome Dino game:

## 📌 Projects
1. [Dino Game with TFT Display](./DinoGame-TFT)  
   - Runs on ESP32 with **TFT_eSPI** library.
   - Features ground, obstacles, and jumping dino character.
   - Hardware: ESP32 + 240x320 TFT Display.

2. [Dino Game with OLED Display](./DinoGame-OLED)  
   - Runs on ESP32 with **Adafruit SSD1306** library.
   - Uses buttons for controls and buzzer for sound effects.
   - Hardware: ESP32 + 128x64 OLED Display.

## 🚀 Getting Started
Each project folder contains its own `README.md` with:
- Hardware requirements
- Library dependencies
- Setup instructions
- Demo screenshots

## 🛠 Tools Used
- [PlatformIO](https://platformio.org/)  
- [Arduino Framework](https://www.arduino.cc/)

---
# Dino Game with TFT Display (ESP32)

## 📖 Overview
This is a **mini clone of the Chrome Dino Game** built on ESP32 using a **TFT Display**.  
The game features:
- Jumping dino
- Random obstacles
- Scoring system
- Smooth graphics with `TFT_eSPI`

## 🛠 Hardware Requirements
- ESP32 DevKit
- 240x320 TFT Display (ILI9341 or similar)
- Jumper wires
- Breadboard (optional)

## 📦 Library Dependencies
- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)

## ⚡ Setup Instructions
1. Clone this repo and open `DinoGame-TFT` in **PlatformIO**.
2. Install required libraries.
3. Connect TFT display pins to ESP32 (configure in `User_Setup.h` of TFT_eSPI).
4. Build and upload firmware.

## ▶️ Controls
- Dino jumps automatically or using button (depending on code).
- Avoid obstacles to increase score.

---
# Dino Game with OLED Display (ESP32)

## 📖 Overview
This project is a **simplified Chrome Dino Game** running on ESP32 with a **128x64 OLED Display**.  
It uses **Adafruit SSD1306** and **Adafruit GFX** for graphics rendering.  
A button is used to control the dino jump, and a buzzer provides sound effects.

## 🛠 Hardware Requirements
- ESP32 DevKit
- 128x64 OLED Display (SSD1306, I2C)
- Push button
- Buzzer (optional)

## 📦 Library Dependencies
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)

## ⚡ Setup Instructions
1. Clone this repo and open `DinoGame-OLED` in **PlatformIO**.
2. Install required libraries.
3. Wire up:
   - OLED SDA → GPIO21  
   - OLED SCL → GPIO22  
   - Button → GPIO4  
   - Buzzer → GPIO5  
4. Build and upload firmware.

## ▶️ Controls
- Press button to jump.
- Avoid obstacles to score points.

---

