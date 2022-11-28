# include "../headers/Player.hpp"

Player::Player()
{
	this->movementSpeed = 100.f;
	this->shape.setSize(sf::Vector2f(32, 32));
}

Player::~Player()
{

}

void Player::Move(const float& dt, const float directionX, const float directionY)
{
	this->shape.move(directionX * this->movementSpeed * dt, directionY * this->movementSpeed * dt);
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Player::Update(const float& dt)
{
	//Movement player in MainState.cpp (updateKeybinds)
}
