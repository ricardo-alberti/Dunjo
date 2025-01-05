#include "World/World.hpp"

int main() {
  Player player = Player(0, 20);
  View view = View();

  World world = World(view, player);
  world.display();

  return 0;
}
