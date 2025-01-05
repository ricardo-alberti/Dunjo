#pragma once

#include "../Entities/Player/Player.hpp"
#include "../View/View.hpp"

class World {
private:
  View &view;
  Player &player;
  float gravity;
  float deltaTime;

public:
  World(View &view, Player &player);
  void display();
};
