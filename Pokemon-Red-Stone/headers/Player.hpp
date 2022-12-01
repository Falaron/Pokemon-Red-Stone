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

# include <thread>
using namespace std;
using namespace sf;

class Player //: public AnimatedPlayer
{
public:
	Player(/*sf::Texture*/);
	//Player();
	~Player();
	void Animation(int);
	virtual void Render(sf::RenderTarget* target);
	virtual void Update(const float& dt,int posT);

	int count;
	int iter;
	bool isMoving;

	//Move character
	virtual void Move(const float& dt, const float directionX, const float directionY);
	virtual void ChangeSpeed(const float speed);

	sf::Sprite shape;
protected:
	float movementSpeed;
	
	sf::Texture tPlayer;
};

#endif