#ifndef FightMenuState_H
#define FightMenuState_H
#include "State.hpp"
#include "../headers/Entity.hpp"
#include "../headers/Pikachu.hpp"

class FightMenuState : public State
// public Entity
{
    float OurMaxHp, OurCurrentHp, EnnemiMaxHp, EnnemiCurrentHp, skillDmg, skillDmgUsed, saveHp1, saveMaxHp1, saveHp2, saveMaxHp2;
    int pos;
    bool pressed, theselect, fightmenu, pokemonmenu, menu, quitFight, textgoing, continueText;
    sf::RectangleShape *winclose;
    sf::Font *font;
    sf::Texture *image;
    sf::Texture imagePikachu;
    sf::Sprite *bg;
    sf::Sprite *pikachu;
    sf::Event event;

    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    std::vector<const char *> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

    sf::Text EnnemiMaxHpText;
    sf::Text EnnemiCurrentHpText;
    sf::Text OurMaxHpText;
    sf::Text OurCurrentHpText;
    sf::Text TextAfterAtk;
    sf::Text TextAfterTakingDmg;
    sf::Text TextEnnemiDmg;
    sf::Text TextOurDmg;
    sf::Text TextYouWon;

    sf::RectangleShape EnnemiHpBox;
    sf::RectangleShape EnnemiHpBar;
    sf::RectangleShape EnnemiHpBarOutline;
    sf::RectangleShape OurHpBox;
    sf::RectangleShape OurHpBar;
    sf::RectangleShape OurHpBarOutline;
    sf::RectangleShape TextBox;
    sf::RectangleShape TextBoxEndFight;

protected:
    void set_values();
    void loop_events();

private:
    // void initKeybinds();
    sf::RectangleShape background;

public:
    FightMenuState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~FightMenuState();

    virtual void Update(const float &data, int posT, sf::View *view) override;
    virtual void UpdateKeybinds(const float &data) override;
    // void UpdateView(const float & dt);
    void Render(sf::RenderWindow *target = nullptr);
    void Menu();
    void Fight();
    void Pokemon();
    void SetPoke();
    void SaveStats();
    void EnnemiHp();
    void OurHp();
    void UpdateHpBar();
    void textAfterAtk();
    void EnnemiAtk();
    void DmgEnnemiHp(int);
    void Run();
    void EndState();
};

#endif
