#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>

class SoundManager {
private:
    sf::Music backgroundMusic;
    bool isMuted;

public:
    SoundManager();
    void playMusic();
    void stopMusic();
    void toggleMute();
    bool isMusicPlaying() const;
};

#endif // SOUNDMANAGER_H
