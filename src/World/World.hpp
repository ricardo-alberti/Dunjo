#pragma once

#include "../Entities/Player/Player.hpp"
#include "../View/View.hpp"
#include "LevelController/LevelController.hpp"
#include "../Utils/CollisionMediator/CollisionMediator.hpp"
#include <memory>

class World {
private:
  View &view;
  Player &player;
  LevelController &levelController;
  std::unique_ptr<CollisionMediator> collisionMediator;

  float deltaTime;
public:
  World(View &view, Player &player, LevelController &levelController);
  void display();
};
