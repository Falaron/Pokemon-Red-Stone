# include "State.hpp"

class MainState :
	public State

{
public:
	MainState(sf::RenderWindow* window);
	virtual ~MainState();

	void Update(const float& data);
	void Render(sf::RenderWindow* target = nullptr);
	void EndState();

private:

};