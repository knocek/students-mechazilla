#include <SFML/Graphics.hpp>
#include "../include/Menu.h"
#include "../include/Game.h"
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Mechazilla Game Menu");

    Menu menu(window);

    while (window.isOpen()) {
        // Obs³uga wejœcia u¿ytkownika
        if (menu.handleInput()) {
            int selected = menu.getSelectedOption();
            if (selected == 0) { // Jeœli wybrano "Play"
                std::cout << "Play selected!" << std::endl;
                Game game(window);   // Utwórz instancjê gry
                game.run();          // Uruchom grê
            } else if (selected == 1) { // Jeœli wybrano "Options"
                std::cout << "Options selected!" << std::endl;
                // Tutaj otwórz ekran opcji (do implementacji)
            } else if (selected == 2) { // Jeœli wybrano "Quit"
                std::cout << "Quit selected!" << std::endl;
                window.close();
            }
        }

        // Rysowanie menu
        menu.draw();
    }

    return 0;
}
