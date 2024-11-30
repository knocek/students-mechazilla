#include "../include/Menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// Konstruktor inicjalizujący menu
Menu::Menu(sf::RenderWindow& window) : window(window), selectedOption(0) {
    if (!font.loadFromFile("../assets/fonts/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        exit(1);
    }

    // Opcje menu
    std::vector<std::string> options = { "Play", "Options", "Quit" };

    // Tworzenie opcji menu
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

// Rysowanie menu na ekranie
void Menu::draw() {
    window.clear();
    for (const auto& option : menuOptions) {
        window.draw(option);
    }
    window.display();
}

// Obsługa wejścia użytkownika
void Menu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
            }
            else if (event.key.code == sf::Keyboard::Down) {
                selectedOption = (selectedOption + 1) % menuOptions.size();
            }
            else if (event.key.code == sf::Keyboard::Return) {
                break;
            }
        }
    }

    // Aktualizuj kolor opcji menu
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        menuOptions[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
    }
}

// Zwraca wybraną opcję
int Menu::getSelectedOption() const {
    return selectedOption;
}
