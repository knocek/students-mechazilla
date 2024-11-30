#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Klasa Menu odpowiedzialna za obs³ugê interfejsu menu gry
class Menu {
private:
    sf::Font font;                          // Font u¿ywany w menu
    std::vector<sf::Text> menuOptions;      // Lista opcji menu
    sf::RenderWindow& window;               // Referencja do okna g³ównego
    int selectedOption;                     // Aktualnie wybrana opcja menu

public:
    Menu(sf::RenderWindow& window);         // Konstruktor
    void draw();                            // Rysuje menu na ekranie
    void handleInput();                     // Obs³uguje wejœcie u¿ytkownika
    int getSelectedOption() const;          // Zwraca aktualnie wybran¹ opcjê
};

#endif // MENU_H
