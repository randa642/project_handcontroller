#include <SoftwareSerial.h>

const int flexSensorPin1 = A0;
const int flexSensorPin2 = A1;
const int flexSensorPin3 = A2;
const int flexSensorPin4 = A3;

const int bluetoothTx = 2;
const int bluetoothRx = 3;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

const int flexThreshold = 500;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(flexSensorPin1, INPUT);
  pinMode(flexSensorPin2, INPUT);
  pinMode(flexSensorPin3, INPUT);
  pinMode(flexSensorPin4, INPUT);
}

void loop() {
  int flexValue1 = analogRead(flexSensorPin1);
  int flexValue2 = analogRead(flexSensorPin2);
  int flexValue3 = analogRead(flexSensorPin3);
  int flexValue4 = analogRead(flexSensorPin4);

  if (flexValue1 > flexThreshold && flexValue2 > flexThreshold) {
    bluetooth.println("F");
    Serial.println("Sending: F (Forward)");
  } else if (flexValue3 > flexThreshold && flexValue4 > flexThreshold) {
    bluetooth.println("B");
    Serial.println("Sending: B (Backward)");
  } else if (flexValue1 > flexThreshold) {
    bluetooth.println("L");
    Serial.println("Sending: L (Left)");
  } else if (flexValue2 > flexThreshold) {
    bluetooth.println("R");
    Serial.println("Sending: R (Right)");
  } else {
    bluetooth.println("T");
    Serial.println("Sending: T (Stop)");
  }

  delay(100);
}
