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
}

int EnnemiPoke::tiplouf() {

    this->life = 50;
    return this->life;
    
}

int EnnemiPoke::caninos() {
    this->life = 25;
    this->pp = 15;
    return(this->life, this->pp);
}


