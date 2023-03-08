#include <M5StickC.h>
#include "Vector3.h"

void setup() {
  M5.begin();
  M5.Mpu6886.Init();

  Serial.begin(9600);
}

const int samplingRate_Hz =   60   /*Hz*/;
const int timeDuration_ms = 1000.0 /*ms*/ / samplingRate_Hz;
int timeMeasuredBefore_ms =    0   /*ms*/;

void loop() {
  // measure with constant interval
  const int timeElapsed_ms = millis() - timeMeasuredBefore_ms;
  if ( timeElapsed_ms < timeDuration_ms ) return;
  timeMeasuredBefore_ms = millis();

  // measure accel
  Vector3 accel;
  M5.Mpu6886.getAccelData(&accel.x, &accel.y, &accel.z);

  // print accel datas
  accel.Print();

  // measure gyro
  Vector3 gyro;
  M5.Mpu6886.getGyroData(&gyro.x, &gyro.y, &gyro.z);

  //print gyro datas
  gyro.Println();
}
