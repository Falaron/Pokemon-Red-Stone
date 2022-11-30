#include "../headers/Pikachu.hpp"
# include "../headers/Entity.hpp"
#include "../headers/Config.hpp"

Pikachu::Pikachu(const sf::Texture& texture) :
    AnimatedEntity(texture, std::vector<sf::IntRect>(PIKACHU_ANIM_RECT))
{
    this->_sprite.scale(10, 10);
    this->life = 0;
    this->pp = 0;
    this->type = 0; //not sure
    this->speed = 0;
    this->dmg = 0;
    imagePikachu.loadFromFile(PIKACHU_TEXTURE_PATH);
    pikachuSprite = new sf::Sprite();
}

int Pikachu::pikachu() {
    pikachuSprite->setTexture(imagePikachu);
    pikachuSprite->setScale(0.25, 0.25);
    pikachuSprite->setPosition(sf::Vector2f(850, 450));
    this->life = 50;
    this->dmg = 15;
    return this->life;
}


