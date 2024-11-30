#include <SFML/Graphics.hpp>
#include "../include/Menu.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mechazilla Game Menu");

    Menu menu(window);

    while (window.isOpen()) {
        menu.handleInput();
        menu.draw();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            int selected = menu.getSelectedOption();
            if (selected == 0) {
                std::cout << "Play selected!" << std::endl;
                // Tutaj uruchom grê
            }
            else if (selected == 1) {
                std::cout << "Options selected!" << std::endl;
                // Tutaj otwórz opcje
            }
            else if (selected == 2) {
                std::cout << "Quit selected!" << std::endl;
                window.close();
            }
        }
    }

    return 0;
}
