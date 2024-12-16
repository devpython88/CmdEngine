#pragma once
#include "CmdEngine"

class CEPhysicsBasic {
  public:
  float velocityX, velocityY;
  float accelerationX, accelerationY;

  CEPhysicsBasic(float accX, float accY): velocityX(0.0f), velocityY(0.0f), accelerationX(accX), accelerationY(accY){}

  protected:
  void applyXPhysics(CERectangle* rec);
  void applyXPhysics(CECircle* rec);
  
  void applyYPhysics(CERectangle* rec);
  void applyYPhysics(CECircle* rec);
};


class CERectanglePhysicsBasic : public CEPhysicsBasic {
  public:
  CERectangle *host;

  CERectanglePhysicsBasic(float accX, float accY, CERectangle *host): CEPhysicsBasic(accX, accY), host(host){}

  void applyXPhysics();
  void applyYPhysics();
};


class CECirclePhysicsBasic : public CEPhysicsBasic {
  public:
  CECircle *host;

  CECirclePhysicsBasic(float accX, float accY, CECircle *host): CEPhysicsBasic(accX, accY), host(host){}

  void applyXPhysics();
  void applyYPhysics();
};