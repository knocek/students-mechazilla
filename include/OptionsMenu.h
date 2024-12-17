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

    std::string& selectedRocket; // selected rocket
    void setupMenu(); // main options setup
    void drawSetRocket(); // function for select rocket


public:
    OptionsMenu(sf::RenderWindow& window, SoundManager& soundManager, std::string& selectedRocket);
    void draw();
    bool handleInput();
    std::string getSelectedRocket() const;
};

#endif // OPTIONSMENU_H
