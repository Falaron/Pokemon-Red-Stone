#pragma once

# define LEFT sf::Keyboard::isKeyPressed(sf::Keyboard::Left)//Left arrow
# define RIGHT sf::Keyboard::isKeyPressed(sf::Keyboard::Right)//Right arrow
# define UP sf::Keyboard::isKeyPressed(sf::Keyboard::Up)//Up arrow
# define DOWN sf::Keyboard::isKeyPressed(sf::Keyboard::Down)//Down arrow

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080

#define PIKACHU_TEXTURE_PATH "sprites\\Pikachu.png"
#define PIKACHU_ANIM_RECT {                                                                                                                            \
        sf::IntRect(0, 0, 100, 100)}