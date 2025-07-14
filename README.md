# 🖱️ ESP32 Air Motion Mouse

This project transforms an ESP32 and an MPU6050 sensor into a **wireless air mouse**. By detecting hand movements using the MPU6050’s gyroscope, the ESP32 sends **Bluetooth mouse movements** to a computer. Two buttons provide **left and right click** functions.

Ideal for presentations, accessibility devices, or just experimenting with BLE HID and motion control.

---

## 🚀 Features

- ✨ Move the mouse with your hand (in the air!)
- 📡 Connects via Bluetooth using BLE HID (no receiver needed)
- 🖱️ Physical buttons for **left and right click**
- 🔋 Low power – MPU sleeps when not connected
- ✅ Works on Windows, Linux, macOS (with BLE)

---

## 🧰 Hardware Requirements

| Component       | Description                         |
|-----------------|-------------------------------------|
| ESP32 Dev Board | With BLE support                    |
| MPU6050         | Gyroscope + Accelerometer sensor    |
| 2x Push Buttons | For left and right mouse clicks     |
| Jumper wires    | For connections                     |
| Power source    | USB or battery                      |

---

## 🔌 Pin Configuration

| MPU6050 Pin | ESP32 Pin |
|-------------|-----------|
| VCC         | 3.3V      |
| GND         | GND       |
| SDA         | GPIO21    |
| SCL         | GPIO22    |

| Button       | ESP32 Pin |
|--------------|-----------|
| Left Click   | GPIO19    |
| Right Click  | GPIO18    |

---

## 📚 Required Libraries

Install these libraries in the Arduino IDE before uploading the code:

| Library Name              | Purpose                                             | Install From                            |
|---------------------------|-----------------------------------------------------|------------------------------------------|
| **Adafruit MPU6050**      | To communicate with the MPU6050 gyroscope sensor   | Arduino Library Manager (Adafruit)       |
| **Adafruit Unified Sensor** | Required for MPU6050 library support             | Arduino Library Manager (Adafruit)       |
| **BleMouse** by T-vK      | Enables BLE HID mouse functionality on ESP32        | GitHub: [T-vK/ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse) |

### 🔧 How to Install Libraries

1. Open **Arduino IDE**
2. Go to **Sketch > Include Library > Manage Libraries**
3. Search and install:
   - `Adafruit MPU6050`
   - `Adafruit Unified Sensor`
4. For **BleMouse**:
   - Visit [https://github.com/T-vK/ESP32-BLE-Mouse](https://github.com/T-vK/ESP32-BLE-Mouse)
   - Click **"Code > Download ZIP"**
   - Extract the folder and place it into your `Documents/Arduino/libraries` folder

---

## 🛠️ How It Works

- **Gyroscope (MPU6050)** detects angular motion (rotation)
- Motion is translated into **X/Y mouse movement**
- **Buttons** perform left and right mouse clicks
- **BLE HID** protocol is used to make the ESP32 behave like a mouse
- When BLE disconnects, MPU sleeps to save power

---

## 🧪 Getting Started

1. Connect the hardware as shown in the pin config above
2. Open `ESP32_Air_Mouse.ino` in Arduino IDE
3. Select your ESP32 board and COM port
4. Install the libraries listed above
5. Upload the code
6. Open Bluetooth settings on your PC and pair with `ESP32 Motion Mouse`
7. Move your device and click the buttons — you're controlling the mouse!

---


## 💡 Future Ideas

- Add support for scrolling (using gyro Y-axis)
- Add power-saving deep sleep mode
- Integrate with gesture recognition
- Add battery monitor and on-screen status
- Volume Control Using 10K potentialmeter

---

Enjoy building your own motion-controlled air mouse! 🛩️🖱️
