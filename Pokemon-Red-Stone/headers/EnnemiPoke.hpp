#pragma once

#include "AnimatedEntity.hpp"

class EnnemiPoke : public AnimatedEntity
{
public:
    EnnemiPoke(const sf::Texture& texture);
    int tiplouf();
    int caninos();
    int chose();
    sf::Texture imagePoke;
    sf::Sprite* PokeSprite;

    int life;
    int pp;
    bool type; //not sure
    int speed;
    int dmg;
    int ennemi;
};