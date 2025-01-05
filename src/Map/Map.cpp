#include "Map.hpp"
#include "Tiles/CentralTileFactory/CentralTileFactory.hpp"
#include "Tiles/TileFactory/TileFactory.hpp"
#include <memory>
#include <vector>

Map::Map() : factory(CentralTileFactory()) {}

void Map::loadTiles() {
  // todo: dinamicly create tiles

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (tileMap[i][j] != 0) {
        int id = tileMap[i][j];
        auto tile =
            factory.createTile(static_cast<TileType>(id), j * 12, i * 12);
        tileObjects.emplace_back(tile);

        if (tile->animated) {
          auto animatedTile = std::dynamic_pointer_cast<AnimatedTile>(tile);
          animated.emplace_back(animatedTile);
        }
      }
    }
  }
}

void Map::draw(sf::RenderWindow &window) {
  for (const auto &tile : tileObjects) {
    window.draw(tile->getSprite());
    //tile->getHitBoxSprite().drawHitBox(window);
  }
}

void Map::Update(float deltaTime) {
  for (const auto &tile : animated) {
    tile->Update(deltaTime);
  }
}

const std::vector<std::shared_ptr<Tile>> &Map::getTiles() const {
  return tileObjects;
}
