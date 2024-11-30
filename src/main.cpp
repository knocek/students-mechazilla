#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Menu.h"
#include "../include/Game.h"
#include "../include/SoundManager.h"
#include "../include/OptionsMenu.h"
#include <iostream>

int main() {
    // Create the main application window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mechazilla Game Menu");

    // Initialize the sound manager
    SoundManager soundManager;
    soundManager.playMusic();

    // Initialize the main menu
    Menu menu(window, soundManager);

    while (window.isOpen()) {
        // Handle user input in the main menu
        if (menu.handleInput()) {
            int selected = menu.getSelectedOption();

            if (selected == 0) { // "Play" selected
                std::cout << "Play selected!" << std::endl;

                // Create and run the game instance
                Game game(window);
                game.run();

            }
            else if (selected == 1) { // "Options" selected
                std::cout << "Options selected!" << std::endl;

                // Create and handle the options menu
                OptionsMenu optionsMenu(window, soundManager);
                optionsMenu.handleInput();

            }
            else if (selected == 2) { // "Quit" selected
                std::cout << "Quit selected!" << std::endl;
                window.close();
            }
        }

        // Draw the main menu
        menu.draw();
    }

    return 0;
}
