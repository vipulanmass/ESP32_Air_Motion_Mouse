
# ESP32 Air Motion Mouse

This project turns your ESP32 into an **air mouse** using motion data from the MPU6050 gyroscope sensor. The device connects via **Bluetooth Low Energy (BLE)** and allows you to move the cursor by physically tilting or rotating the device.

Two onboard push buttons simulate **left and right mouse clicks**, making it a compact and wireless motion-controlled mouse.

## ✨ Features

- BLE HID mouse using ESP32
- Air-based motion control via MPU6050 gyroscope
- Left and right mouse clicks using physical buttons
- Lightweight and battery-friendly
- Ideal for presentations, media control, or accessibility devices

## 🧰 Hardware Requirements

- ESP32 Dev Board  
- MPU6050 (Gyro + Accelerometer)  
- 2x Push Buttons (for left and right click)  
- Battery (optional, for wireless use)

## 📌 Pin Configuration

| Component   | ESP32 Pin |
|-------------|-----------|
| SDA (MPU)   | GPIO21    |
| SCL (MPU)   | GPIO22    |
| Left Click  | GPIO19    |
| Right Click | GPIO18    |

## 🚀 Getting Started

1. Clone this repository
2. Open the `.ino` file in Arduino IDE
3. Install required libraries:
   - `Adafruit MPU6050`
   - `Adafruit Unified Sensor`
   - `BleMouse` (by T-vK)
4. Upload to your ESP32 board
5. Move the board to control your PC cursor wirelessly via Bluetooth!
