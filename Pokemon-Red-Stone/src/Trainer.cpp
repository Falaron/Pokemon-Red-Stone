#include "../headers/Trainer.hpp"
#include "../headers/config.h"

Trainer::Trainer(const sf::Texture& texture) :
    AnimatedPlayer(texture, std::vector<sf::IntRect>(TRAINER_ANIM_RECT))
{
    this->_sprite.scale(4, 4);
}