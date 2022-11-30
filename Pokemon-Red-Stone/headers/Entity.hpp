#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::Sprite _sprite;
    const sf::Texture &_texture;

public:
    Entity(const sf::Texture& texture);
    
    sf::Sprite& getSprite(void);
    const sf::Sprite &getSprite(void) const;

private:
    int life;
    bool pp;
    bool type; //not sure
    int speed;
};