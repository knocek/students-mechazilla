#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Klasa Menu odpowiedzialna za obs�ug� interfejsu menu gry
class Menu {
private:
    sf::Font font;                          // Font u�ywany w menu
    std::vector<sf::Text> menuOptions;      // Lista opcji menu
    sf::RenderWindow& window;               // Referencja do okna g��wnego
    int selectedOption;                     // Aktualnie wybrana opcja menu

public:
    Menu(sf::RenderWindow& window);         // Konstruktor
    void draw();                            // Rysuje menu na ekranie
    void handleInput();                     // Obs�uguje wej�cie u�ytkownika
    int getSelectedOption() const;          // Zwraca aktualnie wybran� opcj�
};

#endif // MENU_H
