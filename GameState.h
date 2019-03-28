#pragma once
#include "State.h"
class GameState :
	public State
{
private:
	Snake snake;
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	//Functions

	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void draw(sf::RenderTarget* target = nullptr);
};

