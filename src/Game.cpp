#include "../include/Game.h"
#include "../include/Rocket.h"
#include "../include/SoundManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// game construktor
Game::Game(sf::RenderWindow& window, const std::string& rocketName) 
    : window(window), inOptions(false) {
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font for game!" << std::endl;
        exit(1);
    }

    //pause image
    if (!pauseTexture.loadFromFile("assets/images/pause.png")) {
        std::cerr << "Failed to load pause button image!" << std::endl;
        exit(1);
    }
    pauseButton.setTexture(pauseTexture);
    pauseButton.setPosition(10, 10); // Ustawienie pozycji przycisku pauzy

    rocket = new Rocket("assets/images/" + rocketName + ".png", rocketName);
    rocket->setPosition(800, 100); // show rocket

    // napis kod gry
    gameText.setFont(font);
    gameText.setString("Kod Gry");
    gameText.setCharacterSize(50);
    gameText.setFillColor(sf::Color::White);
    gameText.setPosition(250, 250);

    // pause text
    pausedText.setFont(font);
    pausedText.setString("GAME PAUSED\nClick ESC to return");
    pausedText.setCharacterSize(30);
    pausedText.setFillColor(sf::Color::White);
    
    // screen size
    sf::FloatRect textRect = pausedText.getLocalBounds();
    sf::Vector2u windowSize = window.getSize();

    // paused text align center
    pausedText.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    pausedText.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

}


void Game::run() {
    while (window.isOpen()) {
        handleInput();
        if (inOptions) {
            drawPausedScreen();
        }
        else {
            draw();
        }
    }
}

void Game::draw() {
    window.clear(sf::Color::Blue);
    window.draw(gameText);
    rocket->draw(window);
    window.draw(pauseButton);
    window.display();
}

// function for pause screen
void Game::drawPausedScreen() {
    window.clear(sf::Color::Black);
    window.draw(pausedText);
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
                inOptions = !inOptions; // pause
            }
        }

        // pause screen
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (pauseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    inOptions = true;
                }
            }
        }
    }
}

Game::~Game() {
    delete rocket;
}