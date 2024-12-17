#ifndef ROCKET_H
#define ROCKET_H

#include <SFML/Graphics.hpp>
#include <string>

class Rocket {
private:
    sf::Texture texture;  // Tekstura rakiety
    sf::Sprite sprite;    // Sprite rakiety
    std::string name;     // Nazwa rakiety

public:
    Rocket(const std::string& texturePath, const std::string& rocketName);

    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) const;

    std::string getName() const;
};

#endif // ROCKET_H
