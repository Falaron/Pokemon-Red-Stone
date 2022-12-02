#include "../headers/Player.hpp"

Player::Player(/* sf::Texture texture */) /* :
AnimatedPlayer(texture, std::vector<sf::IntRect>
{
       sf::IntRect(0, 0, 64, 64), sf::IntRect(64, 0, 64, 64), sf::IntRect(128, 0, 64, 64), sf::IntRect(192, 0, 64, 64)
})*/
{
    // texture = this->tPlayer;
    this->movementSpeed = 150.f;
    this->count = 0;
    this->iter = 0;
    this->shape.setPosition(700, 500);
    this->isMoving = false;
}

Player::~Player()
{
}

void Player::Move(const float &dt, const float directionX, const float directionY)
{
    this->shape.move(directionX * this->movementSpeed * dt, directionY * this->movementSpeed * dt);
    cout << "player pos x : " << this->shape.getPosition().x << " player pos y : " << this->shape.getPosition().y << endl;
    this->isMoving = true;
    cout << "tile x :" << this->getPositionOnMap().x << " "
         << "tile y : " << this->getPositionOnMap().y << endl;
}

void Player::ChangeSpeed(const float speed)
{
    this->movementSpeed = speed;
}

    Vector2f Player::getPlayerPosition() const
{
    return Vector2f(this->shape.getPosition().x, this->shape.getPosition().y);
}

Vector2f Player::getPositionOnMap() const

{   
    // 32 stands for tile size
    return Vector2f(static_cast<int>(this->shape.getPosition().x / 32), static_cast<int>(this->shape.getPosition().y / 32));
}



void Player::Animation(int posT)
{

    if (this->isMoving)
    {
        if (this->count % 30 == 0)
        {
            this->iter = (this->iter + 64) % 256;
            this->shape.setTextureRect(sf::IntRect(this->iter, posT, 64, 64));
            this->count = 0;
        }
        this->count++;
    }
}

void Player::Render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Player::Update(const float &dt, int posT)
{

    if (!this->tPlayer.loadFromFile("sprites/trainer.png"))
    {
        // erreur...
    }
    this->shape.setTexture(this->tPlayer);

    this->Animation(posT);

    // Movement player in MainState.cpp (updateKeybinds)
}