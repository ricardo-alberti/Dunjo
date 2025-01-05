#include "CollisionManager.hpp"
#include <SFML/Graphics/Rect.hpp>

void CollisionManager::checkCollisions(
    Player &player, const std::vector<std::shared_ptr<Tile>> &tiles) {
  for (const auto &tile : tiles) {
    if (tile->getHitBoxSprite().intersects(player.getSprite())) {
      tile->handleCollision(player);

      if (tile->collidable) {
        player.handleCollision(*tile);
      }
    }
  }
}
