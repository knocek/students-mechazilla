#include "../include/SoundManager.h"
#include <iostream>
#include <SFML/Audio.hpp>

SoundManager::SoundManager() : isMuted(false) {
    if (!backgroundMusic.openFromFile("assets/sounds/background-music.ogg")) {
        std::cerr << "Error loading background music!" << std::endl;
        exit(1);
    }
    backgroundMusic.setLoop(true); // Ustawienie pêtli muzyki
}

void SoundManager::playMusic() {
    if (!isMuted) {
        backgroundMusic.play();
    }
}

void SoundManager::stopMusic() {
    backgroundMusic.stop();
}

void SoundManager::toggleMute() {
    isMuted = !isMuted;
    if (isMuted) {
        backgroundMusic.pause();
    }
    else {
        backgroundMusic.play();
    }
}

bool SoundManager::isMusicPlaying() const {
    return !isMuted && backgroundMusic.getStatus() == sf::Music::Playing;
}
