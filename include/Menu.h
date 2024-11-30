#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "../include/SoundManager.h"
#include <vector>
#include <string>

class Menu {
private:
    sf::RenderWindow& window;
    SoundManager& soundManager;
    sf::Font font;
    std::vector<sf::Text> menuOptions;
    int selectedOption; // Indeks wybranej opcji

public:
    Menu(sf::RenderWindow& window, SoundManager& soundManager);
    void draw();
    bool handleInput();
    int getSelectedOption() const; // Deklaracja metody
};

#endif // MENU_H
