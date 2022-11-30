#pragma once

#include "AnimatedEntity.hpp"

class Pikachu : public AnimatedEntity
{
public:
    Pikachu(const sf::Texture& texture);
    int pikachu();
    sf::Texture imagePikachu;
    sf::Sprite* Pokemon;
    int life;
    bool pp;
    bool type; //not sure
    int speed;

};