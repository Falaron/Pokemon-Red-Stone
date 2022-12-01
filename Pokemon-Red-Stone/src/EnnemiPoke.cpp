#include "../headers/EnnemiPoke.hpp"
# include "../headers/Entity.hpp"
#include "../headers/Config.hpp"

EnnemiPoke::EnnemiPoke(const sf::Texture& texture) :
    AnimatedEntity(texture, std::vector<sf::IntRect>(PIKACHU_ANIM_RECT))
{
    this->_sprite.scale(10, 10);
    this->life = 0;
    this->pp = 0;
    this->type = 0; //not sure
    this->speed = 0;
    this->dmg = 0;
    imageTiplouf.loadFromFile("sprites\\tiplouf.png");
    imageCaninos.loadFromFile("sprites\\Pikachu.png");
    TiploufSprite = new sf::Sprite();
    CaninosSprite = new sf::Sprite();
}

int EnnemiPoke::tiplouf() {

    TiploufSprite->setTexture(imageTiplouf);
    TiploufSprite->setScale(0.2, 0.2);
    TiploufSprite->setPosition(sf::Vector2f(950, 420));

    this->life = 50;
    this->dmg = 10;
    return this->life;
    
}

int EnnemiPoke::caninos() {
    CaninosSprite->setTexture(imageCaninos);
    CaninosSprite->setScale(0.25, 0.25);
    CaninosSprite->setPosition(sf::Vector2f(850, 450));

    this->life = 70;
    this->dmg = 15;
    return(this->life);
}






