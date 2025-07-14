#include <Wire.h>
#include <BleMouse.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Button pin definitions
#define LEFTBUTTON 19
#define RIGHTBUTTON 18

// Sensitivity tuning
#define SPEED 15          // Movement multiplier
#define DEAD_ZONE 0.05    // Ignore small gyro movement

Adafruit_MPU6050 mpu;
BleMouse bleMouse("ESP32 Motion Mouse", "OpenAI", 100);  // Device name, manufacturer, battery %

bool mpuSleeping = true;
unsigned long lastLeftClick = 0;
unsigned long lastRightClick = 0;
const int debounceTime = 300; // ms

void setup() {
  Serial.begin(115200);

  // Button setup
  pinMode(LEFTBUTTON, INPUT_PULLUP);
  pinMode(RIGHTBUTTON, INPUT_PULLUP);

  // Start BLE Mouse
  bleMouse.begin();

  // Start I2C for MPU6050
  Wire.begin(21, 22);  // SDA = 21, SCL = 22

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) delay(10);
  }
  Serial.println("MPU6050 Found!");

  // Put MPU to sleep until BLE connects
  mpu.enableSleep(true);
}

void loop() {
  if (bleMouse.isConnected()) {

    if (mpuSleeping) {
      Serial.println("BLE connected. Waking MPU6050...");
      mpu.enableSleep(false);
      mpuSleeping = false;
      delay(500);
    }

    // Read gyro data
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    float gyroX = abs(g.gyro.x) > DEAD_ZONE ? g.gyro.x : 0;
    float gyroZ = abs(g.gyro.z) > DEAD_ZONE ? g.gyro.z : 0;

    int moveX = (int)(gyroZ * -SPEED);  // Left/right
    int moveY = (int)(gyroX * -SPEED);  // Up/down

    if (moveX != 0 || moveY != 0) {
      bleMouse.move(moveX, moveY);
      Serial.printf("Moving: X=%d, Y=%d\n", moveX, moveY);
    }

    // LEFT click
    if (!digitalRead(LEFTBUTTON) && (millis() - lastLeftClick > debounceTime)) {
      bleMouse.click(MOUSE_LEFT);
      lastLeftClick = millis();
      Serial.println("Left click");
    }

    // RIGHT click
    if (!digitalRead(RIGHTBUTTON) && (millis() - lastRightClick > debounceTime)) {
      bleMouse.click(MOUSE_RIGHT);
      lastRightClick = millis();
      Serial.println("Right click");
    }

  } else {
    if (!mpuSleeping) {
      Serial.println("BLE disconnected. Sleeping MPU6050...");
      mpu.enableSleep(true);
      mpuSleeping = true;
    }
  }

  delay(10); // Loop delay for smoother motion
}
