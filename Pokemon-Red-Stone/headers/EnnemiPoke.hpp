#pragma once

#include "AnimatedEntity.hpp"

class EnnemiPoke : public AnimatedEntity
{
public:
    EnnemiPoke(const sf::Texture& texture);
    int tiplouf();
    int caninos();

    sf::Texture imageTiplouf;
    sf::Texture imageCaninos;
    sf::Sprite* TiploufSprite;
    sf::Sprite* CaninosSprite;
    //sf::Sprite* tiplouf;

    int life;
    bool pp;
    bool type; //not sure
    int speed;
    int dmg;

};