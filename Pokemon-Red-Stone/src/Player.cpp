# include "../headers/Player.hpp"
using namespace std;
using namespace sf;

void Player::Input() {

    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        cout << "left key pressed\n";
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        cout << "right key pressed\n";
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        cout << "up key pressed\n";
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        cout << "down key pressed\n";
    }
}