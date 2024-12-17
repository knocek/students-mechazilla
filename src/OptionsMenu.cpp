#include "../include/OptionsMenu.h"
#include <iostream>

// Constructor
OptionsMenu::OptionsMenu(sf::RenderWindow& window, SoundManager& soundManager, std::string& selectedRocket)
    : window(window), soundManager(soundManager), selectedOption(0), selectedRocket(selectedRocket) {
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

        // align text center
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
bool OptionsMenu::handleInput() {
    bool shouldExit = false;

    while (window.isOpen()) {
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
                    if (selectedOption == 0) { // Set Rocket
                        std::cout << "Set Rocket!" << std::endl;
                        drawSetRocket();
                        //selectedOption = 2;
                        //return true;
                    }
                    else if (selectedOption == 1) { // Toggle Music
                        soundManager.toggleMute();
                        //return true;

                    }
                    else if (selectedOption == 2) { // Back
                        std::cout << "Option 2-Returning to main menu..." << std::endl;
                        shouldExit = true;
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
    return true;
}

// change rocket
void OptionsMenu::drawSetRocket() {
    std::vector<std::string> rockets = { "Rocket1", "Rocket2", "Rocket3" };
    int selectedRocketOption = 0;

    for (size_t i = 0; i < rockets.size(); ++i) {
        if (rockets[i] == selectedRocket) {
            selectedRocketOption = i;
            break;
        }
    }

    while (window.isOpen()) {
        window.clear();

        // show rockets
        for (size_t i = 0; i < rockets.size(); ++i) {
            sf::Text text;
            text.setFont(font);
            text.setString(rockets[i]);
            text.setCharacterSize(40);
            text.setPosition(300, 200 + i * 60);
            text.setFillColor(i == selectedRocketOption ? sf::Color::Red : sf::Color::White);
            window.draw(text);
        }

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedRocketOption = (selectedRocketOption - 1 + rockets.size()) % rockets.size();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedRocketOption = (selectedRocketOption + 1) % rockets.size();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    selectedRocket = rockets[selectedRocketOption];
                    std::cout << "Selected Rocket in drawSetRocket: " << selectedRocket << std::endl;
                    return;
                }
            }
        }
    }
}


std::string OptionsMenu::getSelectedRocket() const {
    return selectedRocket; // Zwraca aktualnie wybraną rakietę
}