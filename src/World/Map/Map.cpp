#include "Map.hpp"
#include <memory>
#include <vector>

Map::Map(const std::vector<std::vector<int>> &tileMap)
    : tileMap(tileMap), factory(CentralTileFactory()) {
  if (tileMap.empty() || tileMap[0].empty()) {
    throw std::runtime_error("Invalid or empty tileMap");
  }
}

void Map::loadTiles() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (tileMap[i][j] == 0)
        continue;

      int id = tileMap[i][j];
      auto tile = factory.createTile(static_cast<TileType>(id), j * 12, i * 12);
      tiles.emplace_back(tile);

      if (tile->isAnimated()) {
        auto animatedTile = std::dynamic_pointer_cast<AnimatedTile>(tile);
        animatedTiles.emplace_back(animatedTile);
      }
    }
  }
}

void Map::draw(sf::RenderWindow &window) {
  for (const auto &tile : tiles) {
    window.draw(tile->getSprite());
    //tile->getHitBoxSprite().drawHitBox(window);
  }
}

void Map::Update(float deltaTime) {
  for (const auto &tile : animatedTiles) {
    tile->Update(deltaTime);
  }
}

const std::vector<std::shared_ptr<Tile>> &Map::getTiles() const {
  return tiles;
}
