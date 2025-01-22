#include "CollisionMediator.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

void CollisionMediator::checkCollisions(
    Player &player, const std::vector<std::shared_ptr<Tile>> &tiles) {
  for (const auto &tile : tiles) {
    if (!tile->getHitBoxSprite().intersects(player.getHitBoxSprite()))
      continue;

    if (tile->isCollidable())
      handleDirectionalCollisions(*tile, player);

    tile->handleCollision(player);
  }
}

void CollisionMediator::handleDirectionalCollisions(Tile &tile,
                                                    Player &player) {
  sf::FloatRect playerBounds = player.getHitBoxSprite().getRect();
  sf::FloatRect tileBounds = tile.getHitBoxSprite().getRect();

  if (playerBounds.top + playerBounds.height - COLLISION_MARGIN <=
      tileBounds.top) {
    player.blockDownMovement(tileBounds.top - playerBounds.height);
  }

  else if (playerBounds.top + COLLISION_MARGIN >=
           tileBounds.top + tileBounds.height) {
    player.blockUpMovement(tileBounds.top + tileBounds.height);
  }

  else if (playerBounds.left + playerBounds.width - COLLISION_MARGIN >=
           tileBounds.left) {
    player.blockRightMovement(tileBounds.left + tileBounds.width +
                              playerBounds.width / 2 - COLLISION_MARGIN);
  }

  else if (playerBounds.left - COLLISION_MARGIN <=
           tileBounds.left + tileBounds.width) {
    player.blockLeftMovement(tileBounds.left - playerBounds.width / 2 -
                             COLLISION_MARGIN);
  }
}

void CollisionMediator::handleSlabCollisions(Tile &tile, Player &player) {}
