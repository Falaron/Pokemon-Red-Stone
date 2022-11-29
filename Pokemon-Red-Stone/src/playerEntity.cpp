#include "../headers/PlayerEntity.hpp"

PlayerEntity::PlayerEntity(const sf::Texture& texture) : _sprite(texture), _texture(texture)
{
}

sf::Sprite& PlayerEntity::getSprite(void)
{
    return this->_sprite;
}

const sf::Sprite& PlayerEntity::getSprite(void) const
{
    return this->_sprite;
}