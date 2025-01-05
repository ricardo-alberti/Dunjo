cmake_minimum_required(VERSION 3.21)
project(Dunjo)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 REQUIRED graphics window system)

set(SOURCES
    src/View/View.cpp
    src/Entities/Player/Player.cpp
    src/Utils/CollisionManager/CollisionManager.cpp
    src/World/World.cpp
    src/Utils/Animation/Animation.cpp
    src/Map/Tiles/Fire/Fire.cpp
    src/Map/Tiles/Brick/Brick.cpp
    src/Map/Tiles/Coin/Coin.cpp
    src/Map/Tiles/Brick/BrickFactory/BrickFactory.cpp
    src/Map/Tiles/Tile.cpp
    src/Map/Map.cpp
    src/Settings/Settings.cpp
    src/main.cpp
)

add_executable(Dunjo ${SOURCES})
target_link_libraries(Dunjo PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
