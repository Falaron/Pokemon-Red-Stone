#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include "MainState.hpp"

class MainMenuState : public State
{
private:
    sf::Event event;

    int pos;
    bool theselect;
    sf::RectangleShape *winclose;
    sf::Font *font;
    sf::Texture *image;
    sf::Sprite *bg;

    std::vector<const char *> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

    sf::RectangleShape background;

    /* SOUND */

public:
    MainMenuState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~MainMenuState();

    void SetValues();
    virtual void Update(const float &dt, int posT, sf::View *view) override;
    virtual void UpdateKeybinds(const float &dt) override;
    // void UpdateView(const float & dt);
    virtual void Render(sf::RenderWindow *target = nullptr) override;

    void EndState();
};

#endif
