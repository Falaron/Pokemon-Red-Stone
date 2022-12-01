#include "../headers/EnnemiPoke.hpp"
# include "../headers/Entity.hpp"
#include "../headers/Config.hpp"
# include <stdlib.h>
using namespace std;


EnnemiPoke::EnnemiPoke(const sf::Texture& texture) :
    AnimatedEntity(texture, std::vector<sf::IntRect>(PIKACHU_ANIM_RECT))
{
    this->_sprite.scale(10, 10);
    this->life = 0;
    this->pp = 0;
    this->type = 0; //not sure
    this->speed = 0;
    this->dmg = 0;

    imagePoke.loadFromFile("sprites\\pokemon.png");
    PokeSprite = new sf::Sprite();
}

int EnnemiPoke::tiplouf() {

    PokeSprite->setTexture(imagePoke);
    PokeSprite->setTextureRect(sf::IntRect(0, 90, 90, 90));
    PokeSprite->setScale(3, 3);
    PokeSprite->setPosition(sf::Vector2f(750, 400));

    this->life = 50;
    this->dmg = 10;
    return this->life;
    
}

int EnnemiPoke::caninos() {
    PokeSprite->setTexture(imagePoke);
    PokeSprite->setTextureRect(sf::IntRect(0, 0, 100, 100));

    PokeSprite->setScale(3, 3);


    PokeSprite->setPosition(sf::Vector2f(1050, 450));

    this->life = 70;
    this->dmg = 15;
    return(this->life);
}

int EnnemiPoke::chose()
{
    if (rand() % 3 == 1){
        caninos();
    }
    else
    {
        tiplouf();
    }

    //ennemi = rand() % 3;
    //switch (ennemi)
    //{
    //case 1:
    //    caninos();
    //case 2:
    //    tiplouf();  



    //default:
    //    break;
    //}
    return 0;
}