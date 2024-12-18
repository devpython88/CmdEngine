#include "cephysics.h"

void CEPhysicsBasic::applyXPhysics(CECircle* rec)
{
  velocityX += accelerationX;
  rec->x += velocityX;
}

void CEPhysicsBasic::applyYPhysics(CECircle* rec)
{
  velocityY += accelerationY;
  rec->y += velocityY;
}

void CEPhysicsBasic::applyXPhysics(CERectangle* rec)
{
  velocityX += accelerationX;
  rec->x += velocityX;
}

void CEPhysicsBasic::applyYPhysics(CERectangle* rec)
{
  velocityY += accelerationY;
  rec->y += velocityY;
}



void CERectanglePhysicsBasic::applyXPhysics()
{
  CEPhysicsBasic::applyXPhysics(host);
}

void CERectanglePhysicsBasic::applyYPhysics()
{
  CEPhysicsBasic::applyYPhysics(host);
}

void CECirclePhysicsBasic::applyXPhysics()
{
  CEPhysicsBasic::applyXPhysics(host);
}

void CECirclePhysicsBasic::applyYPhysics()
{
  CEPhysicsBasic::applyYPhysics(host);
}
