# include "../headers/Game.hpp"

int main()
{
    sf::Texture texture;
    if (!texture.loadFromFile("sprites\\Trainer.png"))
    {
        // error...
    }
    Player player = Player(texture);
    

    Game game;
    game.InitWindow(1000, 1000, "Pokemon Red Stone");
    int count = 0;
    while (game.isOpen())
    {
        game.clear();
        game.Update();
        if (count % 20 == 0)
        {
            player.nextAnimation();
            count = 0;
        }
        count++;

        player.Input();
        game.drawEntity(player);
        game.display();
    }


    return 0;
}
