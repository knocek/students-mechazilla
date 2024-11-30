#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "SoundManager.h"

// Klasa Menu odpowiedzialna za obs�ug� interfejsu menu gry
class Menu {
private:
    sf::Font font;                          // Font u�ywany w menu
    std::vector<sf::Text> menuOptions;      // Lista opcji menu
    sf::RenderWindow& window;               // Referencja do okna g��wnego
    int selectedOption;                     // Aktualnie wybrana opcja menu
    SoundManager& soundManager; // referencja do SoundManager
    std::vector<sf::Text> optionsMenu; // Opcje ekranu "Options"
    std::string username; // Przechowywana nazwa u�ytkownika

public:
    Menu(sf::RenderWindow& window, SoundManager& soundManager);         // Konstruktor
    void draw();                            // Rysuje menu na ekranie
    bool handleInput();                     // Obs�uguje wej�cie u�ytkownika
    int getSelectedOption() const;          // Zwraca aktualnie wybran� opcj�
    void drawOptions(); //rysowanie menu opcji
    void enterUsername();
};

#endif // MENU_H