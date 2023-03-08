#include <M5StickC.h>
#include "Vector3.h"

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Mpu6886.Init();

  Serial.begin(9600);
}

const int samplingRate_Hz =   60   /*Hz*/;
const int timeDuration_ms = 1000.0 /*ms*/ / samplingRate_Hz;
int timeMeasuredBefore_ms =    0   /*ms*/;

void loop() {
  const int timeElapsed_ms = millis() - timeMeasuredBefore_ms;
  if ( timeElapsed_ms < timeDuration_ms ) return;
  timeMeasuredBefore_ms = millis();

  Vector3 accel;
  M5.Mpu6886.getAccelData(&accel.x, &accel.y, &accel.z);
  Serial.printf("t:%d, x:%f, y:%f, z:%f, magnitude:%f\n", 
                timeElapsed_ms, accel.x, accel.y, accel.z, accel.Magnitude());

}
