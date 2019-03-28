#include "State.h"



State::State(sf::RenderWindow* window)
{
	this->window = window;
}


State::~State()
{
}

void State::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		quit = true;
	
}

const bool & State::getQuit() const
{
	return quit;
}
