#pragma once

#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <memory>
#include <unordered_map>

class MusicManager {
private:
  std::unordered_map<std::string, std::string> musicPaths;
  std::unordered_map<std::string, std::unique_ptr<sf::Music>> activeMusic;

  MusicManager() {
    musicPaths["background"] = "../assets/music/background.mp3";
  }

public:
  static MusicManager &getInstance() {
    static MusicManager instance;
    return instance;
  }

  MusicManager(const MusicManager &) = delete;
  MusicManager &operator=(const MusicManager &) = delete;

  bool play(const std::string &musicName) {
    auto it = musicPaths.find(musicName);
    if (it == musicPaths.end()) {
      std::cerr << "Music not found: " << musicName << std::endl;
      return false;
    }

    auto music = std::make_unique<sf::Music>();
    if (!music->openFromFile(it->second)) {
      std::cerr << "Failed to load music: " << it->second << std::endl;
      return false;
    }

    music->play();
    music->setVolume(5.0f);
    music->setLooping(true);
    activeMusic[musicName] = std::move(music);

    return true;
  }

  void stop(const std::string &musicName) {
    auto it = activeMusic.find(musicName);
    if (it != activeMusic.end()) {
      it->second->stop();
      activeMusic.erase(it);
    }
  }

  void stopAll() {
    for (auto &pair : activeMusic) {
      pair.second->stop();
    }
    activeMusic.clear();
  }
};
