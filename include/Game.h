#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "../include/Rocket.h"
#include <string>

class Game {
private:
    sf::RenderWindow& window;      // main window reference
    sf::Font font;                 // game font
    sf::Text gameText;             // Napis "Kod Gry"
    sf::Text pausedText;            // Tekst "GAME PAUSED"

    sf::Texture pauseTexture;       // texture for pause button
    sf::Sprite pauseButton;         // sprite for pause button

    bool inOptions;                // if menu selected

    Rocket* rocket; // dynamic rocket function

public:
    Game(sf::RenderWindow& window, const std::string& rocketName);  // game constructor
    ~Game();

    void run();                      // main game loop
    void draw();                     // draw game elements
    void handleInput();              // input
    void drawPausedScreen();         //draw pause screen
};

#endif // GAME_H
