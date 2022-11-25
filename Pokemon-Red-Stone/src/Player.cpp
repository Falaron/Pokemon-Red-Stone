//# include "../headers/Player.hpp"
//using namespace std;
//using namespace sf;
//
//Player::Player(const sf::Texture& texture) :
//    //this->PlayerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
//    AnimatedEntity(texture, std::vector<sf::IntRect>{ 
//        sf::IntRect(0, 0, 64, 64), sf::IntRect(64, 0, 64, 64),
//        sf::IntRect(128, 0, 64, 64), sf::IntRect(192, 0, 64, 64) })
//    {
//        this->_sprite.scale(1, 1);
//    }
//
//
//void Player::PlayerMove(const float& dt, const float positionX, const float positionY)
//{
//        this->PlayerSprite.move(positionX * speed * dt, positionY * speed * dt);
//}
//
