#include <Arduino.h>

#ifndef VECTOR3_H
#define VECTOR3_H

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

#endif