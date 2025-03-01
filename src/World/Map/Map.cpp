#include "World/Map.hpp"
#include "Tiles/MagicBrick.hpp"

Map::Map(const std::vector<std::vector<int>> &tileMap)
    : tileMap(tileMap), factory(CentralTileFactory()) {
  if (tileMap.empty() || tileMap[0].empty()) {
    throw std::runtime_error("Invalid or empty tileMap");
  }
}

void Map::loadTiles() {
  tiles.clear();
  animatedTiles.clear();
  magicBricks.clear();
  levelComputer = nullptr;

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (tileMap[i][j] == 0) // empty
        continue;

      if (tileMap[i][j] == 99) // player spawn point
      {
        spawnPoint = {12.0f * j, 12.0f * i};
        continue;
      }

      int id = tileMap[i][j];
      auto tile = factory.createTile(static_cast<TileType>(id), j * 12, i * 12);
      tiles.emplace_back(tile);

      if (levelComputer != nullptr && tileMap[i][j] == 28) // magicBrick
      {
        auto magickBrick = std::dynamic_pointer_cast<class MagicBrick>(tile);
        levelComputer->AddObserver(magickBrick);
      } else if (tileMap[i][j] == 28) // magicBrick
      {
        auto magickBrick = std::dynamic_pointer_cast<class MagicBrick>(tile);
        magicBricks.emplace_back(magickBrick);
      }

      if (tileMap[i][j] == 23) // computer
      {
        levelComputer = std::dynamic_pointer_cast<class Computer>(tile);

        if (magicBricks.size() != 0)
          for (std::shared_ptr<class MagicBrick> m : magicBricks)
            levelComputer->AddObserver(m);
      }

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
    // tile->getHitBoxSprite().drawHitBox(window);
  }
}

void Map::Update(float deltaTime) {
  for (const auto &tile : tiles) {
    tile->Update(deltaTime);
  }
}

const std::vector<std::shared_ptr<Tile>> &Map::getTiles() const {
  return tiles;
}

const sf::Vector2f &Map::getSpawnPoint() const { return spawnPoint; }
