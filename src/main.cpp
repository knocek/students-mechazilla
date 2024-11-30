#include <SFML/Graphics.hpp>
#include "../include/Menu.h"
#include "../include/Game.h"
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Mechazilla Game Menu");

    Menu menu(window);

    while (window.isOpen()) {
        // Obs�uga wej�cia u�ytkownika
        if (menu.handleInput()) {
            int selected = menu.getSelectedOption();
            if (selected == 0) { // Je�li wybrano "Play"
                std::cout << "Play selected!" << std::endl;
                Game game(window);   // Utw�rz instancj� gry
                game.run();          // Uruchom gr�
            } else if (selected == 1) { // Je�li wybrano "Options"
                std::cout << "Options selected!" << std::endl;
                // Tutaj otw�rz ekran opcji (do implementacji)
            } else if (selected == 2) { // Je�li wybrano "Quit"
                std::cout << "Quit selected!" << std::endl;
                window.close();
            }
        }

        // Rysowanie menu
        menu.draw();
    }

    return 0;
}
