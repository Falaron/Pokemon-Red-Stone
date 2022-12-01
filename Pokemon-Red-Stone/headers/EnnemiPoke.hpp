#pragma once

#include "AnimatedEntity.hpp"

class EnnemiPoke : public AnimatedEntity
{
public:
    EnnemiPoke(const sf::Texture& texture);
    int tiplouf();
    int caninos();

    sf::Texture imageTiplouf;
    sf::Sprite* ennemiPoke;
    //sf::Sprite* tiplouf;

    int life;
    int pp;
    bool type; //not sure
    int speed;

};