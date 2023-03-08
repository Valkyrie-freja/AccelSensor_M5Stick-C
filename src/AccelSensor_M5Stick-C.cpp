#include <M5StickC.h>
#include "Vector3.h"

void setup() {
  M5.begin();
  M5.Mpu6886.Init();

  Serial.begin(9600);
}

const int kSamplingRate_Hz     =   60   /*Hz*/;
const int kSamplingInterval_ms = 1000.0 /*ms*/ / kSamplingRate_Hz;
int millisBefore_ms = 0 /*ms*/;

void loop() {
  // measure with constant interval
  int interval_ms = millis() - millisBefore_ms;
  if ( interval_ms < kSamplingInterval_ms ) return;
  millisBefore_ms = millis();

  // measure accel and gyro.
  Vector3 accel;
  Vector3 gyro;
  M5.Mpu6886.getAccelData(&accel.x, &accel.y, &accel.z);
  M5.Mpu6886.getGyroData(&gyro.x, &gyro.y, &gyro.z);

  // send serial message.
  char serial_message[64];
  sprintf(serial_message, "%f, %f, %f, %f, %f, %f\n",
          accel.x, accel.y, accel.z, gyro.x, gyro.y, gyro.z);
  Serial.print(serial_message);
}
