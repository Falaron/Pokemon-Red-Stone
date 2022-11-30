#pragma once

#include "AnimatedEntity.hpp"

class Pikachu : public AnimatedEntity
{
public:
    Pikachu(const sf::Texture& texture);

    int life;
    bool pp;
    bool type; //not sure
    int speed;

};