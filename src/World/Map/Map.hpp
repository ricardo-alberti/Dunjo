#pragma once

#include "TileAspects/AnimatedTile.hpp"
#include "TileFactories/CentralTileFactory/CentralTileFactory.hpp"
#include "Tiles/Tile.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

const int WIDTH = 23;
const int HEIGHT = 15;

class Map {
protected:
  std::vector<std::vector<int>> tileMap;
  std::vector<std::shared_ptr<Tile>> tiles;
  std::vector<std::shared_ptr<AnimatedTile>> animatedTiles;
  CentralTileFactory factory;

public:
  Map(const std::vector<std::vector<int>> &tileMap);
  void loadTiles();
  void draw(sf::RenderWindow &window);
  void Update(float deltaTime);
  const std::vector<std::shared_ptr<Tile>> &getTiles() const;
};