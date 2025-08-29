# Ultrasonic Sensor Distance Measurement using ESP-IDF on ESP32  

This project demonstrates how to interface an **HC-SR04 ultrasonic sensor** with the **ESP32** using the **ESP-IDF framework**.  
The ESP32 sends a trigger pulse, measures the echo pulse width, and calculates the distance based on the speed of sound.  

---

## 📌 Features
- Written in pure ESP-IDF (no Arduino libraries).  
- Uses `gpio_set_level`, `gpio_get_level`, and `esp_timer_get_time` for precise pulse measurement.  
- Logs measured distance values using `ESP_LOGI`.  
- Modular library structure (`ultrasonic.c` / `ultrasonic.h`) for easy reuse in other projects.  

---

## 🛠️ Hardware Connections (ESP32 ↔ HC-SR04)
| ESP32 Pin | HC-SR04 Pin |
|-----------|-------------|
| GPIO4     | Trigger     |
| GPIO13    | Echo        |
| 3.3V      | VCC         |
| GND       | GND         |

> ⚠️ Important: Use a voltage divider (e.g., 1kΩ + 2kΩ resistors) between HC-SR04 **Echo** and ESP32 GPIO to step down 5V → 3.3V safely.
> DONT SUPPLY 5V DIRECTLY TO THE SENSOR

---
