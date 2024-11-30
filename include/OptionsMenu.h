#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../include/SoundManager.h"

class OptionsMenu {
private:
    sf::RenderWindow& window;
    sf::Font font;
    SoundManager& soundManager;
    std::vector<sf::Text> menuOptions;
    int selectedOption;

    void setupMenu();

public:
    OptionsMenu(sf::RenderWindow& window, SoundManager& soundManager);
    void draw();
    void handleInput();
};

#endif // OPTIONSMENU_H
