#pragma once

#include "AnimatedEntity.hpp"

class Pikachu : public AnimatedEntity
{
public:
    Pikachu(const sf::Texture& texture);
    int pikachu();
    sf::Texture imagePikachu;
    sf::Sprite* pikachuSprite;
    int life;
    bool pp;
    bool type; //not sure
    int speed;
    int dmg;
    int skillDmg1;
    int skillDmg2;
    int skillDmg3;
    int skillDmg4;

};