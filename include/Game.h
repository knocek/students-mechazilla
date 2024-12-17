#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "../include/Rocket.h"
#include <string>

// Klasa odpowiedzialna za logik� gry
class Game {
private:
    sf::RenderWindow& window;      // Referencja do g��wnego okna
    sf::Font font;                 // Font u�ywany w grze
    sf::Text gameText;             // Napis "Kod Gry"
    sf::RectangleShape menuButton; // Znaczek menu
    bool inOptions;                // Czy jeste�my w menu opcji

    Rocket* rocket; // Dynamiczna rakieta



public:
    Game(sf::RenderWindow& window, const std::string& rocketName);  // Konstruktor
    ~Game();

    void run();                      // G��wna p�tla gry
    void draw();                     // Rysowanie element�w gry
    void handleInput();              // Obs�uga wej�cia u�ytkownika
    void drawOptions();            // Rysowanie menu opcji
};

#endif // GAME_H
