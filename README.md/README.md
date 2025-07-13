# 🌿 Plant Monitoring System using ESP32 + ThingSpeak + MATLAB Email Alert

## 📌 Overview
This project is designed to monitor environmental conditions of a plant, including **soil moisture**, **temperature**, and **humidity**, using the ESP32 microcontroller. The data is sent to **ThingSpeak** cloud, and an **email alert** is triggered automatically via **MATLAB** when the plant is too dry.

---

## 🧠 Features

- 📈 Real-time temperature, humidity, and moisture tracking
- ☁️ Data upload to **ThingSpeak IoT cloud**
- 📧 Email alert using **MATLAB cloud trigger**
- 🔌 Completely wireless monitoring using ESP32
- 💻 Local display via Serial Monitor
- 🔔 Works without any physical display (no OLED required)

---

## 🛠️ Hardware Used

| Component           | Description                     |
|--------------------|---------------------------------|
| ESP32 Dev Board    | Main microcontroller             |
| DHT11/DHT22        | Temperature & Humidity sensor    |
| Soil Moisture Sensor | Analog soil moisture reading  |
| MQ135              | Gas sensor
| Jumper Wires       | For connections                  |
| USB Cable          | For power + programming          |

---

## 🧰 Software/Cloud Used

- **Arduino IDE** (ESP32 Board core)
- **ThingSpeak** (for IoT data upload and logging)
- **MATLAB** (to trigger email alert from cloud)
- **VS Code / Notepad** (for code + email script)

---

## 🔧 Circuit Connections (Text Summary)

- **DHT11 Data Pin** → GPIO 22 (Digital Input)  
- **Soil Moisture Analog Out** → GPIO 34 (Analog Input)  
- **MQ135 Sensor Analog Out** → GPIO 35  (Analog Input)  
- **ESP32** connected to Wi-Fi network  
- ThingSpeak Channel ID and API Key used for uploading sensor data  
- MATLAB trigger file monitors moisture and sends email if low

---

## 🖼️ Output Images

> *(All images are in `/Images/` folder)*

- 📊 ThingSpeak Graphs  
- 📨 Email Alert Screenshot

---

## 📹  Video

> *(Located in `/Videos/` folder or linked here)*  
[▶️ Watch Video of Working System](https://drive.google.com/file/d/14xUpk34x8UfeaVOeBAp0LRyfbgWHzMuS/view?usp=sharing)

---

## 📂 Folder Structure
  
---

## 👨‍💻 Author

**Rahul B**  
1st Year B.Tech | Embedded & IoT Enthusiast  
GitHub: [github.com/yourusername](https://github.com/RahulSPB)

---

## 💡 Future Improvements

- Add OLED or LCD for live display  
- Add moisture threshold buzzer alert  
- Add Firebase/Blynk integration for mobile view  
- Control pump/actuator based on soil status

---

## 🏁 Status

✅ Fully functional and tested locally  
📧 Email alert via MATLAB confirmed working  
🛠️ Clean wiring and simple design  
📁 Documented and ready for showcase

