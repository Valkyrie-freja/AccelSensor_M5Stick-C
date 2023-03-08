#include <M5StickC.h>

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.Mpu6886.Init();

  Serial.begin(9600);
}

class Vector3{
  public:
    float x, y, z;
    Vector3(float _x, float _y, float _z){
      x = _x;
      y = _y;
      z = _z;
    };
    Vector3(){
      x = y = z = 0.0f;
    }
    float Magnitude(){
      return sqrt(x*x + y*y + z*z);
    }
    Vector3 Norm(){
      float magnitude = this->Magnitude();
      Vector3 norm(x, y, z);
      norm.x /= magnitude;
      norm.y /= magnitude;
      norm.z /= magnitude;
      return norm;
    };
};

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
