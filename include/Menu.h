#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "../include/SoundManager.h"
#include "../include/Rocket.h"
#include <vector>
#include <string>

class Menu {
private:
    sf::RenderWindow& window;
    SoundManager& soundManager;

    std::vector<sf::Text> menuOptions;
    int selectedOption;

    //font
    sf::Font font;

    //background
    sf::Texture textureMenu; // Tekstura tla
    sf::Sprite spriteBG;

public:
    Menu(sf::RenderWindow& window, SoundManager& soundManager);
    void draw();
    bool handleInput();
    int getSelectedOption() const; // Deklaracja metody
};

#endif // MENU_H
