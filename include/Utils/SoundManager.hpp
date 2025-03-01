#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>
#include <memory>
#include <unordered_map>

class SoundManager {
private:
  std::unordered_map<std::string, std::string> soundPaths;
  std::unordered_map<std::string, std::shared_ptr<sf::Sound>> activeSounds;
  std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
  std::unordered_map<std::string, float> soundVolumes;

  SoundManager() {
    soundPaths["coin"] = "../assets/sound/coin.wav";
    soundPaths["jump"] = "../assets/sound/jump.wav";
    soundPaths["computer"] = "../assets/sound/computer.wav";
    soundPaths["slime"] = "../assets/sound/slime.wav";
    soundPaths["door"] = "../assets/sound/door.wav";

    soundVolumes["jump"] = 0.5f;
    soundVolumes["door"] = 100.0f;
  }

public:
  static SoundManager &getInstance() {
    static SoundManager instance;
    return instance;
  }

  SoundManager(const SoundManager &) = delete;
  SoundManager &operator=(const SoundManager &) = delete;

  bool play(const std::string &soundName) {
    auto it = soundPaths.find(soundName);
    if (it == soundPaths.end()) {
      std::cerr << "Sound not found: " << soundName << std::endl;
      return false;
    }

    auto bufferIt = soundBuffers.find(soundName);
    if (bufferIt == soundBuffers.end()) {
      sf::SoundBuffer soundBuffer;
      if (!soundBuffer.loadFromFile(it->second)) {
        std::cerr << "Failed to load sound: " << it->second << std::endl;
        return false;
      }
      soundBuffers[soundName] = std::move(soundBuffer);
    }

    if (activeSounds.find(soundName) == activeSounds.end()) {
      activeSounds[soundName] =
          std::make_shared<sf::Sound>(soundBuffers[soundName]);
    } else {
      activeSounds[soundName]->setBuffer(soundBuffers[soundName]);
    }

    float volume = (soundVolumes.find(soundName) != soundVolumes.end())
                       ? soundVolumes[soundName]
                       : 5.0f;
    activeSounds[soundName]->setVolume(volume);

    activeSounds[soundName]->play();

    return true;
  }

  void stop(const std::string &soundName) {
    auto it = activeSounds.find(soundName);
    if (it != activeSounds.end()) {
      it->second->stop();
    }
  }

  void stopAll() {
    for (auto &pair : activeSounds) {
      pair.second->stop();
    }
    activeSounds.clear();
  }
};
