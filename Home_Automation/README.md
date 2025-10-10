# 🏠 Home Automation System
An IoT-Based Smart Home Project using Node-RED  

---

## 📘 Project Overview
This project demonstrates an **IoT-based Home Automation System** that allows users to **control and monitor home appliances remotely** using **Node-RED**.  
It provides a modular and flexible automation setup that can be easily deployed on **Raspberry Pi**, **ESP32**, or any IoT-enabled platform.

---

## ⚙️ Features
- 🌐 Web-based dashboard for controlling home devices  
- 💡 Real-time monitoring of device status  
- 🔔 Alerts or notifications on state changes  
- 🧠 Fully customizable Node-RED flow  
- 📱 Compatible with mobile and desktop browsers  

---

## 🧩 Technologies Used
| Component | Description |
|------------|-------------|
| **Node-RED** | Flow-based programming tool for IoT systems |
| **MQTT / HTTP** | Communication protocols between devices |
| **Raspberry Pi / ESP32** | Hardware platform for automation |
| **JSON** | Node-RED flow configuration format |

---

## 📁 Project Structure
```
Home_Automation/
│
├── home_automation.json     # Node-RED flow for automation logic
├── task_1.mkv               # Demonstration video of the project
└── README.md                # Project documentation
```

---

## 🎥 Demo Video
Watch the project demonstration:  
📹 `task_1.mkv` (included in this repository)

---

## 🚀 How to Run the Project
1. **Install Node-RED** on your system (Raspberry Pi, Ubuntu, etc.):  
   ```bash
   sudo apt install nodered
   ```
2. **Start Node-RED:**
   ```bash
   node-red
   ```
3. **Open Node-RED editor in your browser:**  
   ```
   http://localhost:1880
   ```
4. **Import the flow:**
   - Go to **Menu → Import → home_automation.json**
   - Click **Deploy**
5. **Test your system** using actual devices or simulated nodes.

---

## 🔒 Future Improvements
- Integration with **Google Assistant** or **Alexa**  
- Adding **temperature**, **humidity**, and **motion sensors**  
- Mobile app integration for remote access  
- Energy consumption tracking

---

## 👨‍💻 Author
**Ahmed Elkerdawy**  
🔗 [GitHub](https://github.com/ahmedelkerdawy)  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmed-elkerdawy-b43206247/)
