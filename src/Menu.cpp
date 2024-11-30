#include "../include/Menu.h"
#include "../include/OptionsMenu.h"
#include <iostream>

// Constructor
Menu::Menu(sf::RenderWindow& window, SoundManager& soundManager)
    : window(window), soundManager(soundManager), selectedOption(0) {
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        exit(1);
    }

    // Main menu options
    std::vector<std::string> options = { "Play", "Options", "Quit" };

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(40);
        text.setPosition(300, 200 + i * 60);
        text.setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
        menuOptions.push_back(text);
    }
}

// Draw main menu
void Menu::draw() {
    window.clear();
    for (const auto& option : menuOptions) {
        window.draw(option);
    }
    window.display();
}

int Menu::getSelectedOption() const {
    return selectedOption;
}

// Handle main menu input
bool Menu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return false;
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
            }
            else if (event.key.code == sf::Keyboard::Down) {
                selectedOption = (selectedOption + 1) % menuOptions.size();
            }
            else if (event.key.code == sf::Keyboard::Return) {
                if (selectedOption == 1) { // Open Options Menu
                    OptionsMenu optionsMenu(window, soundManager);
                    optionsMenu.handleInput();
                }
                else if (selectedOption == 2) { // Quit
                    window.close();
                }
                return true;
            }
        }

        // Update colors
        for (size_t i = 0; i < menuOptions.size(); ++i) {
            menuOptions[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
        }
    }

    return false;
}
