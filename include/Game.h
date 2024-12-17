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
    sf::RectangleShape menuButton; // menu icon
    bool inOptions;                // if menu selected

    Rocket* rocket; // dynamic rocket function



public:
    Game(sf::RenderWindow& window, const std::string& rocketName);  // game constructor
    ~Game();

    void run();                      // main game loop
    void draw();                     // draw game elements
    void handleInput();              // input
    void drawOptions();              //draw menu options
};

#endif // GAME_H
