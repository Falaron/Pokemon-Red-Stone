# include "../headers/Player.hpp"
using namespace std;
using namespace sf;

Player::Player(const sf::Texture& texture) :
    //this->PlayerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    AnimatedEntity(texture, std::vector<sf::IntRect>{ 
        sf::IntRect(0, 0, 64, 64), sf::IntRect(64, 0, 64, 64),
        sf::IntRect(128, 0, 64, 64), sf::IntRect(192, 0, 64, 64)
})
{
    this->_sprite.scale(10, 10);
}



