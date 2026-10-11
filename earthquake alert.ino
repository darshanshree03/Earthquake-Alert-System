#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

unsigned long timer = 0;
int threshold = 2;  // Sensitivity for detecting movement
int ledPin = 8;     // LED Pin
int buzzerPin = 9;  // Buzzer Pin

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    Serial.begin(9600);
    Wire.begin();

    byte status = mpu.begin();
    Serial.print("MPU6050 status: ");
    Serial.println(status);

    while (status != 0) {
        Serial.println("MPU6050 connection failed. Check wiring.");
        delay(1000);
    }

    Serial.println("Calibrating...");
    mpu.calcOffsets();  // Takes ~5 seconds
    Serial.println("Done calibrating!");

}

void loop() {
    mpu.update();

    int accX = mpu.getAccX();
    int accY = mpu.getAccY();
    int accZ = mpu.getAccZ();

    float magnitude = sqrt(accX * accX + accY * accY + accZ * accZ);

    // Debugging: Print magnitude to check the sensor output
    Serial.print("Magnitude: ");
    Serial.println(magnitude);

    if (magnitude > threshold) {
        unsigned long currentMillis = millis();

        if (currentMillis - timer > 500) {  // Ensure motion lasts for at least 500ms
            Serial.println("Vibration detected! Triggering alert...");

            digitalWrite(ledPin, HIGH);     // Turn on LED
            digitalWrite(buzzerPin, HIGH);  // Turn on Buzzer
            delay(1000);                    // Keep alert for 1 second
            digitalWrite(ledPin, LOW);      // Turn off LED
            digitalWrite(buzzerPin, LOW);   // Turn off Buzzer

            timer = currentMillis;          // Reset timer
        }
    }

    // Print the accelerometer data to serial monitor
    Serial.print("Acc X: "); Serial.print(accX);
    Serial.print(" | Acc Y: "); Serial.print(accY);
    Serial.print(" | Acc Z: "); Serial.println(accZ);

    delay(700);  // Delay to slow down the data output in the Serial Monitor
}
