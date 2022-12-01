# include "../headers/Player.hpp"

Player::Player(/* sf::Texture texture */ ) /* :
AnimatedPlayer(texture, std::vector<sf::IntRect>
{                                                                                                                            
        sf::IntRect(0, 0, 64, 64), sf::IntRect(64, 0, 64, 64), sf::IntRect(128, 0, 64, 64), sf::IntRect(192, 0, 64, 64) 
})*/
{
    //texture = this->tPlayer;
    this->movementSpeed = 100.f;
    this->count = 0;
    this->iter = 0;
}


Player::~Player()
{

}

void Player::Move(const float& dt, const float directionX, const float directionY)
{
	this->shape.move(directionX * this->movementSpeed * dt, directionY * this->movementSpeed * dt);
	this->isMoving = true;

}


void Player::Animation(int posT) {


    Player player;

    if (this->isMoving) {
        if (this->count % 30 == 0)
        {
            this->iter = (this->iter + 64) % 256;
            this->shape.setTextureRect(sf::IntRect(this->iter, posT, 64, 64));
            this->count = 0;
        }
        this->count++;
    }
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
    
    this->Animation(posT);
    
    //Movement player in MainState.cpp (updateKeybinds)
}