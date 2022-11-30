#include "../headers/Tile.hpp"
#include "Tile.hpp"
#include <sstream>
Tile::Tile()
{
    this->collision = false;
    this->type = TileTypes::DEFAULT;
}

Tile::Tile(unsigned gridSizeF, unsigned gridX, unsigned gridY, const Texture& texture, const IntRect& textureRect,
    bool collision, short type)
{
    this->sprite.setSize(sf::Vector2f(gridSizeF, gridSizeF));
    this->sprite.setFillColor(sf::Color::Green);
    this->sprite.setPosition(static_cast<float>(gridX) * gridSizeF, static_cast<float>(gridY) * gridSizeF);
    this->sprite.setTexture(&texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->collision = collision;
    this->type = type;
}

const string Tile::getAsString() const
{
    std::stringstream ss;

    ss << this->type << " " << this->collision;
    ss << this->sprite.getTextureRect().left << " " << this->sprite.getTextureRect().top << " " 
    << this->collision << " " << this->type;

    return ss.str();
}

void Tile::update()
{
}


void Tile::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

Tile::~Tile()
{

}