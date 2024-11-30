#include "../include/Game.h"
#include "../include/SoundManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Konstruktor gry
Game::Game(sf::RenderWindow& window) : window(window), inOptions(false) {
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font for game!" << std::endl;
        exit(1);
    }

    gameText.setFont(font);
    gameText.setString("Kod Gry");
    gameText.setCharacterSize(50);
    gameText.setFillColor(sf::Color::White);
    gameText.setPosition(250, 250);

    menuButton.setSize(sf::Vector2f(50, 50));
    menuButton.setFillColor(sf::Color::Green);
    menuButton.setPosition(10, 10);
}

void Game::run() {
    bool isRunning = true;

    while (isRunning && window.isOpen()) {
        handleInput();
        if (inOptions) {
            drawOptions();
        }
        else {
            draw();
        }
    }
}

void Game::draw() {
    window.clear(sf::Color::Blue);
    window.draw(gameText);
    window.draw(menuButton);
    window.display();
}

void Game::drawOptions() {
    window.clear(sf::Color::Black);

    sf::Text optionsText;
    optionsText.setFont(font);
    optionsText.setString("Options Menu\nPress ESC to return to the main menu");
    optionsText.setCharacterSize(30);
    optionsText.setFillColor(sf::Color::White);
    optionsText.setPosition(100, 100);

    window.draw(optionsText);
    window.display();
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                if (inOptions) {
                    inOptions = false;
                }
                else {
                    window.close();
                }
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (menuButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    inOptions = true;
                }
            }
        }
    }
}
