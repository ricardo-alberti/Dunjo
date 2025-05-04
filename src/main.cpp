#include "World/World.hpp"

int main() {
  Player player;
  View view;
  LevelController levelController; 

  World world = World(view, player, levelController);

  world.display();

  return 0;
}
