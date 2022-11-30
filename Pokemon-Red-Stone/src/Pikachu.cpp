#include "../headers/Pikachu.hpp"
# include "../headers/Entity.hpp"
#include "../headers/Config.hpp"

Pikachu::Pikachu(const sf::Texture& texture) :
    AnimatedEntity(texture, std::vector<sf::IntRect>(PIKACHU_ANIM_RECT))
{
    this->_sprite.scale(10, 10);
    this->life = 20;
    this->pp = 20;
    this->speed = 40;
}


