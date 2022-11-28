# include "../headers/Game.hpp"

void Game::InitWindow(int width, int height, const char* title)
{

    this->window = new RenderWindow(VideoMode(width, height), title, (Style::Titlebar, Style::Close));
}

void Game::InitStates()
{
    this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
    this->InitWindow(1920, 1080, "Pokemon : Red Stone");
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

void Game::UpdateDeltaTime()
{
    this->deltaTime = this->deltaClock.restart().asSeconds();
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
    Player player;
    while (this->window->pollEvent(event))
    {
        if (event.type == Event::Closed) {
            this->states.top()->EndState();
            delete this->states.top();
            this->states.pop();
        }
        /*int count = 0;
        if (count % 20 == 0)
        {
            player.nextAnimation();
            count = 0;
        }
        count++;*/
    }



    if (!this->states.empty())
    {
        this->states.top()->Update(this->deltaTime,0);

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


