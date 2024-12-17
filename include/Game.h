#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "../include/Rocket.h"
#include <string>

// Klasa odpowiedzialna za logikê gry
class Game {
private:
    sf::RenderWindow& window;      // Referencja do g³ównego okna
    sf::Font font;                 // Font u¿ywany w grze
    sf::Text gameText;             // Napis "Kod Gry"
    sf::RectangleShape menuButton; // Znaczek menu
    bool inOptions;                // Czy jesteœmy w menu opcji

    Rocket* rocket; // Dynamiczna rakieta



public:
    Game(sf::RenderWindow& window, const std::string& rocketName);  // Konstruktor
    ~Game();

    void run();                      // G³ówna pêtla gry
    void draw();                     // Rysowanie elementów gry
    void handleInput();              // Obs³uga wejœcia u¿ytkownika
    void drawOptions();            // Rysowanie menu opcji
};

#endif // GAME_H
