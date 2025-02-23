cmake_minimum_required(VERSION 3.21)
project(Dunjo)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    src/View/View.cpp
    src/Entities/Player/Player.cpp
    src/Utils/CollisionMediator/CollisionMediator.cpp
    src/World/World.cpp
    src/Utils/Animation/Animation.cpp
    src/World/LevelController/LevelController.cpp
    src/World/Map/Tiles/Fire/Fire.cpp
    src/World/Map/Tiles/Door/Door.cpp
    src/World/Map/Tiles/Brick/Brick.cpp
    src/World/Map/Tiles/Coin/Coin.cpp
    src/World/Map/TileFactories/BrickFactory/BrickFactory.cpp
    src/World/Map/Tiles/Tile.cpp
    src/World/Map/Map.cpp
    src/Settings/Settings.cpp
    src/main.cpp
)

add_executable(Dunjo ${SOURCES})
target_link_libraries(Dunjo PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
