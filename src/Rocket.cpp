#include "../include/Rocket.h"
#include <iostream>

// Konstruktor: ³adowanie tekstury i ustawienie sprite'a
Rocket::Rocket(const std::string& texturePath, const std::string& rocketName) : name(rocketName) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load rocket texture: " << texturePath << std::endl;
        exit(1);
    }
    sprite.setTexture(texture);
}

void Rocket::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Rocket::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

std::string Rocket::getName() const {
    return name;
}
