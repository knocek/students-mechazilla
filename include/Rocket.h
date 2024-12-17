#ifndef ROCKET_H
#define ROCKET_H

#include <SFML/Graphics.hpp>
#include <string>

class Rocket {
private:
    sf::Texture texture;  // rocket texture
    sf::Sprite sprite;    // rocket sprite 
    std::string name;     // rocket name

public:
    Rocket(const std::string& texturePath, const std::string& rocketName);

    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) const;

    std::string getName() const;
};

#endif // ROCKET_H
