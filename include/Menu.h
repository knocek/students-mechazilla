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

    // font
    sf::Font font;

    // background
    sf::Texture textureMenu; // background texture
    sf::Sprite spriteBG;

    std::string selectedRocket;


public:
    Menu(sf::RenderWindow& window, SoundManager& soundManager, const std::string& rocketName);
    void draw();
    bool handleInput();
    int getSelectedOption() const; // method declaration
    void updateSelectedRocket(const std::string& newRocket);
};

#endif // MENU_H
