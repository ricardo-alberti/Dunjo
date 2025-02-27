#include "World/World.hpp"

int main() {
  Player player = Player();
  View view = View();
  LevelController levelController = LevelController();

  World world = World(view, player, levelController);
  world.display();

  return 0;
}
