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

  sf::Vector2f playerPos = playerBounds.position;
  sf::Vector2f playerSize = playerBounds.size;
  sf::Vector2f tilePos = tileBounds.position;
  sf::Vector2f tileSize = tileBounds.size;

  float playerBottom = playerPos.y + playerSize.y - COLLISION_MARGIN;
  float playerTop = playerPos.y + COLLISION_MARGIN;
  float playerRight = playerPos.x + playerSize.x - COLLISION_MARGIN;
  float playerLeft = playerPos.x - COLLISION_MARGIN;

  float tileBottom = tilePos.y + tileSize.y;
  float tileRight = tilePos.x + tileSize.x;

  if (playerBottom <= tilePos.y) {
    player.blockDownMovement(tilePos.y - playerSize.y);
  } else if (playerTop >= tileBottom) {
    player.blockUpMovement(tileBottom);
  } else if (playerRight >= tilePos.x) {
    player.blockRightMovement(tilePos.x + tileSize.x + playerSize.x / 2 -
                              COLLISION_MARGIN);
  } else if (playerLeft <= tileRight) {
    player.blockLeftMovement(tilePos.x - playerSize.x / 2 - COLLISION_MARGIN);
  }
}

void CollisionMediator::handleSlabCollisions(Tile &tile, Player &player) {}
