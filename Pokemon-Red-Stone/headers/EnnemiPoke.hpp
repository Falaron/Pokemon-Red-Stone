#pragma once

#include "AnimatedEntity.hpp"

class EnnemiPoke : public AnimatedEntity
{
public:
    EnnemiPoke(const sf::Texture& texture);
    int tiplouf();
    int caninos();

    int life;
    bool pp;
    bool type; //not sure
    int speed;

};