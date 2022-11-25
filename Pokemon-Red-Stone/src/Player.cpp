# include "../headers/Player.hpp"

Player::Player()
{
	this->movementSpeed = 100.f;
	sf::Texture tPlayer;
	tPlayer.loadFromFile("sprites/trainer.png");
	sf::Sprite sPlayer(tPlayer);
}

Player::~Player()
{

}

void Player::Move(const float& dt, const float directionX, const float directionY)
{
	//this->sprite.move(directionX * this->movementSpeed * dt, directionY * this->movementSpeed * dt);
}

void Player::Render(sf::RenderTarget* target)
{
	//target->draw(this->sPlayer);
}

void Player::Update(const float& dt)
{
	//Movement player in MainState.cpp (updateKeybinds)
	
}

//void Player::DrawSprite(sf::Sprite sprite)
//{
//	this->target.draw(sprite);
//}
