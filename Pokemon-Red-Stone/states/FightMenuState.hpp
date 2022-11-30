#ifndef FightMenuState_H
#define FightMenuState_H
#include "State.hpp"
#include "../headers/Entity.hpp"
#include "../headers/Pikachu.hpp"

class FightMenuState :
	public State
	//public Entity
{
	int pos;
	bool pressed, theselect, fightmenu, pokemonmenu, menu ;
	sf::RectangleShape* winclose;
	sf::Font* font;
	sf::Texture* image;
	sf::Texture imagee;
	sf::Sprite* bg;

	sf::Sprite* pikachu;
	sf::Sprite* tiplouf;
	sf::Event event;

	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;

	std::vector<const char*> options;
	std::vector<sf::Vector2f> coords;
	std::vector<sf::Text> texts;
	std::vector<std::size_t> sizes;
protected:
	void set_values();
	void loop_events();

private:
	//void initKeybinds();
	sf::RectangleShape background;

public:
	FightMenuState(sf::RenderWindow* window, std::stack<State*>* states/*, std::map<std::string, int>* supportedKeys*/);
	virtual ~FightMenuState();

	void Update(const float& data, int posT);
	void UpdateKeybinds(const float& data);
	void Render(sf::RenderWindow* target = nullptr);
	void Menu();
	void Fight();
	void Pokemon();
	void Run();
	void EndState();
};

#endif

