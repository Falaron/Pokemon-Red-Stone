#include "../headers/Entity.hpp"
#include "../headers/Game.hpp"


Entity::Entity(const sf::Texture& texture) : _sprite(texture), _texture(texture)
{
    this->life = 0;
    this->pp = 0;
    this->type = 0;
    this->speed = 0;
}

sf::Sprite& Entity::getSprite(void)
{
    return this->_sprite;
}

const sf::Sprite& Entity::getSprite(void) const
{
    return this->_sprite;
}