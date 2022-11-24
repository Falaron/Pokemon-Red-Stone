# include "../headers/Game.hpp"

void Game::InitWindow(int width, int height, const char* title)
{

    this->window = new RenderWindow(VideoMode(width, height), title, (Style::Titlebar, Style::Close));
    this->window->setFramerateLimit(30);
}

void Game::InitStates()
{
    this->states.push(new MainState(this->window));
}

Game::Game()
{
    this->InitWindow(800, 500, "Pokemon : Red Stone");
    this->InitStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::Run()
{
    while (this->window->isOpen())
    {
        this->UpdateDeltaTime();
        this->Update();
        this->Render();
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
        if (event.type == Event::Closed) {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
    }

    if (!this->states.empty())
    {
        this->states.top()->Update(this->deltaTime);

        if (this->states.top()->GetQuit())
        {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else this->window->close(); // End Game
}

void Game::Render()
{
    this->window->clear();

    //window.draw(map); //draw map
    //this->window.draw(PlayerSprite);
    if (!this->states.empty()) this->states.top()->Render(this->window);
    this->window->display();
}
//void Game::drawEntity(const Entity& entity)
//{
//    this->window->draw(entity.getSprite());
//}

void Game::UpdateDeltaTime()
{
    this->deltaTime = this->deltaClock.getElapsedTime().asSeconds();
}
