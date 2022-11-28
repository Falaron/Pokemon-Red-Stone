# include "../headers/Player.hpp"
# include "../headers/AnimatedPlayer.hpp"


Player::Player(/* sf::Texture texture */ ) /* :
AnimatedPlayer(texture, std::vector<sf::IntRect>
{                                                                                                                            
		sf::IntRect(0, 0, 64, 64), sf::IntRect(64, 0, 64, 64), sf::IntRect(128, 0, 64, 64), sf::IntRect(192, 0, 64, 64) 
})*/
{
	//texture = this->tPlayer;
	this->movementSpeed = 100.f;
}

/*Player::Player() {

}*/


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

void Player::Update(const float& dt, int posT)
{


	if (!this->tPlayer.loadFromFile("sprites/trainer.png"))
	{
		// erreur...
	}
	this->shape.setTexture(this->tPlayer);
	
	this->shape.setTextureRect(sf::IntRect(posT, posT, 64, 64));
	
	//Movement player in MainState.cpp (updateKeybinds)
}
