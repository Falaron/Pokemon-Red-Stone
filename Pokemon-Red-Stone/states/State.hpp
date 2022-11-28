#pragma once

# include "../headers/Player.hpp"

class State {
public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	virtual void Render(sf::RenderWindow* target = NULL) = 0;
	virtual void Update(const float& dt, int posT) = 0;
	virtual void UpdateKeybinds(const float& dt) = 0;

	virtual void CheckForQuit();
	const bool& GetQuit() const;


	virtual void EndState() = 0;
	//sf::RenderWindow* window;

protected:
	std::stack<State*>* states;

	std::map<std::string, sf::Texture> textures;
	sf::RenderWindow* window;

	bool quit;
};

