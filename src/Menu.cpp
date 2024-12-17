#include "../include/Menu.h"
#include "../include/OptionsMenu.h"
#include <iostream>

// Constructor
Menu::Menu(sf::RenderWindow& window, SoundManager& soundManager, const std::string& rocketName)
    : window(window), soundManager(soundManager), selectedOption(0), selectedRocket(rocketName) {
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        exit(1);
    }

    //background
    if (!textureMenu.loadFromFile("assets/images/main-background.jpg")) {
        std::cerr << "Error loading background image!" << std::endl;
        exit(1);
    }

    spriteBG.setTexture(textureMenu);
    spriteBG.setPosition(0, 0);

    // Main menu options
    std::vector<std::string> options = { "Play", "Options", "Quit" };

    for (size_t i = 0; i < options.size(); ++i) {
    sf::Text text;
    text.setFont(font);
    text.setString(options[i]);
    text.setCharacterSize(40);
    
    sf::FloatRect textBounds = text.getLocalBounds();
    // text align center
    float textX = (1920 / 2.0f) - (textBounds.width / 2.0f);
    float textY = (1080 / 2.0f) - (options.size() * 60 / 2.0f) + i * 60;
    text.setPosition(textX, textY);
    text.setFillColor(i == selectedOption ? sf::Color::Blue : sf::Color::White);
    
    menuOptions.push_back(text);
    }
}

void Menu::updateSelectedRocket(const std::string& newRocket) {
    selectedRocket = newRocket; // update selected rocket
    std::cout << "Updated Rocket in Menu: " << selectedRocket << std::endl;
}

// Draw main menu
void Menu::draw() {
    window.clear();
    window.draw(spriteBG);
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
                    OptionsMenu optionsMenu(window, soundManager, selectedRocket);
                    
                    if (optionsMenu.handleInput()) {
                        selectedRocket = optionsMenu.getSelectedRocket();
                        updateSelectedRocket(selectedRocket);
                    }
                    
                    //optionsMenu.handleInput();
                    // selectedOption = -1;
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
