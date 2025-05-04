#pragma once

class Movable {

public:
  void setForce(float _horizontalForce, float _verticalForce);
  void addForce(float _horizontalForce, float _verticalForce);

  void resetVerticalVelocity();
  void resetHorizontalVelocity();

  void blockLeftMovement(float x);
  void blockRightMovement(float x);
  void blockDownMovement(float y);
  void blockUpMovement(float y);
};
