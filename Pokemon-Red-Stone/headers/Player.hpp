#include <SFML/Graphics.hpp>
#include "AnimatedEntity.hpp"

class Player : public AnimatedEntity 
{
public:
	void Input();
	Player(const sf::Texture &texture);
	//Player();
private:
	sf::Texture PlayerTexture;
	sf::Sprite PlayerSprite;
	int positionX = 0;
	int positionY = 0;
	int speed = 5;
};