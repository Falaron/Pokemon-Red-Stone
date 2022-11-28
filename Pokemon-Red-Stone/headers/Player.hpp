#ifndef PLAYER_H
#define PLAYER_H

# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Audio.hpp>

# include <ctime>
# include <map>
# include <stack>
# include <iostream>
using namespace std;
using namespace sf;

class Player
{
public:
	Player();
	~Player();

	virtual void Render(sf::RenderTarget* target);
	virtual void Update(const float& dt);

	//Move character
	virtual void Move(const float& dt, const float directionX, const float directionY);
 
protected:
	float movementSpeed;
	sf::RectangleShape shape;
};

#endif