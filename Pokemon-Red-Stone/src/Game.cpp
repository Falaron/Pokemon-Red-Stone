# include "../headers/Game.hpp"

using namespace sf;
using namespace std;

void Game::InitWindow(int width, int height, const char* title)
{

    this->window = new RenderWindow(VideoMode(width, height), title, (Style::Titlebar, Style::Close));
    this->window->setFramerateLimit(30);
}

Game::Game()
{
    this->InitWindow(800, 500, "Pokemon : Red Stone");
}

Game::~Game()
{
    delete this->window;
}

void Game::Run()
{
    while (this->window->isOpen())
    {
        this->Update();
        //this->Render();
    }
}

bool Game::isOpen(void) const
{
    return this->window->isOpen();
}

void Game::Update()
{
    while (this->window->pollEvent(event))
    {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            this->window->close();
    }

    //player.Input(); //Keyboard detection  
}

void Game::Render()
{
    this->window->clear();
    //window.draw(map); //draw map
    //this->window.draw(PlayerSprite);
    this->window->display();
}
void Game::clear() {
    this->window->clear();
}

void Game::display() {
    this->window->display();
}

void Game::drawEntity(const Entity& entity)
{
    this->window->draw(entity.getSprite());
}