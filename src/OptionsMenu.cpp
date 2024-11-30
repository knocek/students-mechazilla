#include "../include/OptionsMenu.h"
#include <iostream>

// Constructor
OptionsMenu::OptionsMenu(sf::RenderWindow& window, SoundManager& soundManager)
    : window(window), soundManager(soundManager), selectedOption(0) {
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        exit(1);
    }
    setupMenu();
}

// Setup menu options
void OptionsMenu::setupMenu() {
    menuOptions.clear();
    std::vector<std::string> options = { "Set Rocket", "Turn off/on Music", "Back to options" };

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(40);

        sf::FloatRect textBounds = text.getLocalBounds();

        // Wyœrodkuj tekst
        float textX = (1920 / 2.0f) - (textBounds.width / 2.0f);
        float textY = (1080 / 2.0f) - (options.size() * 60 / 2.0f) + i * 60;

        text.setPosition(textX, textY);
        text.setFillColor(i == selectedOption ? sf::Color::Blue : sf::Color::White);
        menuOptions.push_back(text);
    }
}

// Draw the menu
void OptionsMenu::draw() {
    window.clear();
    for (const auto& option : menuOptions) {
        window.draw(option);
    }
    window.display();
}

// Handle input for the menu
void OptionsMenu::handleInput() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedOption = (selectedOption + 1) % menuOptions.size();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    if (selectedOption == 0) { // Set Username
                        std::cout << "Set Username selected!" << std::endl;
                        // Add username functionality
                    }
                    else if (selectedOption == 1) { // Toggle Music
                        soundManager.toggleMute();
                    }
                    else if (selectedOption == 2) { // Back
                        return; // Exit options menu
                    }
                }

                // Update option colors
                for (size_t i = 0; i < menuOptions.size(); ++i) {
                    menuOptions[i].setFillColor(i == selectedOption ? sf::Color::Blue : sf::Color::White);
                }
            }
        }

        draw(); // Redraw menu
    }
}
