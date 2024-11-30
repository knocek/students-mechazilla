#include "../include/Menu.h"
#include "../include/SoundManager.h"
#include <iostream>
#include <SFML/Audio.hpp>

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

void Menu::draw() {
    window.clear();
    for (const auto& option : menuOptions) {
        window.draw(option);
    }
    window.display();
}

void Menu::drawOptions() {
    optionsMenu.clear();
    std::vector<std::string> options = { "Set Username", "Turn off/on Music", "Back" };

    // Create option texts
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(40);
        text.setPosition(300, 200 + i * 60);
        text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::White); // Default to first option highlighted
        optionsMenu.push_back(text);
    }

    int selectedOptionInOptions = 0;

    while (window.isOpen()) {
        window.clear();

        // Draw options menu
        for (size_t i = 0; i < optionsMenu.size(); ++i) {
            window.draw(optionsMenu[i]);
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
                    selectedOptionInOptions = (selectedOptionInOptions - 1 + optionsMenu.size()) % optionsMenu.size();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedOptionInOptions = (selectedOptionInOptions + 1) % optionsMenu.size();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    if (selectedOptionInOptions == 0) { // Set Username
                        enterUsername();
                    }
                    else if (selectedOptionInOptions == 1) { // Toggle Music
                        soundManager.toggleMute();
                    }
                    else if (selectedOptionInOptions == 2) { // Back
                        return; // Exit options menu
                    }
                }

                // Update option colors
                for (size_t i = 0; i < optionsMenu.size(); ++i) {
                    optionsMenu[i].setFillColor(i == selectedOptionInOptions ? sf::Color::Red : sf::Color::White);
                }
            }
        }
    }
}




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
                soundManager.playMusic();
            }
            else if (event.key.code == sf::Keyboard::Down) {
                selectedOption = (selectedOption + 1) % menuOptions.size();
                soundManager.playMusic();
            }
            else if (event.key.code == sf::Keyboard::Return) {
                if (selectedOption == 1) {
                    drawOptions(); // Open the options menu
                }
                return true;
            }
        }
    }

    for (size_t i = 0; i < menuOptions.size(); ++i) {
        menuOptions[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
    }

    return false;
}

void Menu::enterUsername() {
    // Display prompt for username input
    sf::Text prompt;
    prompt.setFont(font);
    prompt.setString("Enter your username:");
    prompt.setCharacterSize(30);
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(200, 200);

    // Display for the user input
    std::string userInput;
    sf::Text userInputDisplay;
    userInputDisplay.setFont(font);
    userInputDisplay.setCharacterSize(30);
    userInputDisplay.setFillColor(sf::Color::Green);
    userInputDisplay.setPosition(200, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            // Handle user input
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!userInput.empty()) {
                        userInput.pop_back();
                    }
                }
                else if (event.text.unicode == '\r') { // Handle Enter key
                    username = userInput; // Save the username
                    std::cout << "Username set to: " << username << std::endl;
                    return; // Exit this function
                }
                else if (event.text.unicode < 128) { // Append valid ASCII characters
                    userInput += static_cast<char>(event.text.unicode);
                }
            }
        }

        // Update user input display
        userInputDisplay.setString(userInput);

        // Render the prompt and user input
        window.clear();
        window.draw(prompt);
        window.draw(userInputDisplay);
        window.display();
    }
}

int Menu::getSelectedOption() const {
    return selectedOption;
}
