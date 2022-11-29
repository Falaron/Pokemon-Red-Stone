#pragma once

#include "../headers/playerEntity.hpp"

class AnimatedPlayer : public PlayerEntity
{
protected:
    size_t _count;
    std::vector<sf::IntRect> _animation_pos;

public:
    AnimatedPlayer(const sf::Texture&, std::vector<sf::IntRect>);
    void nextAnimation(void);
};