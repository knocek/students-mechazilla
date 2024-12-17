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

    std::string selectedRocket; // Wybrana rakieta
    void setupMenu(); // Ustawienia g��wnego menu opcji
    void drawSetRocket(); // Funkcja wyboru rakiety


public:
    OptionsMenu(sf::RenderWindow& window, SoundManager& soundManager);
    void draw();
    void handleInput();
    std::string getSelectedRocket() const; // Funkcja zwracaj�ca wybran� rakiet�
};

#endif // OPTIONSMENU_H
