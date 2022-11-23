# include "../headers/Game.hpp"

int main()
{
    Player player;
    player.Input();
    player.PrintPlayer("sprites\\Trainer.png");

    Game game;
    game.Run();

    return 0;
}
