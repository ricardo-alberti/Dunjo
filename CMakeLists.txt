cmake_minimum_required(VERSION 3.21)
project(Dunjo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(SOURCES
    src/View/View.cpp
    src/Entities/Player.cpp
    src/World/World.cpp
    src/Utils/Settings.cpp
    src/Utils/CollisionMediator.cpp
    src/Utils/Animation.cpp
    src/Utils/LevelController.cpp
    src/Tiles/Fire.cpp
    src/Tiles/Door.cpp
    src/Tiles/Brick.cpp
    src/Tiles/Coin.cpp
    src/Tiles/Tile.cpp
    src/Factories/BrickFactory.cpp
    src/Map/Map.cpp
    src/main.cpp
)

add_executable(Dunjo ${SOURCES})
target_link_libraries(Dunjo PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
