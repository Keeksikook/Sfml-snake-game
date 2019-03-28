#include "GameState.h"



GameState::GameState(sf::RenderWindow* window)
	:
	State(window),
	snake({ 400, 300 }, { 80, 0 })
{
}

GameState::~GameState()
{
	endState();
}

void GameState::endState()
{
}

void GameState::updateInput(const float & dt)
{
	checkQuit();
}

void GameState::update(const float& dt)
{
	updateInput(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		snake.steer(-2.5*dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		snake.steer(2.5*dt);
	snake.update(dt);
	
}

void GameState::draw(sf::RenderTarget* target)
{
	if (!target)
		target = window;
	snake.draw(target);
}

