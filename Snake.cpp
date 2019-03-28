#include "Snake.h"

bool Snake::hitSelf()
{
	bool hit = 0;
	for (int i = 1; i < cells.size(); i++)
		if (head.distToEntity(*cells[i]) - 2 * 6 <= 0)
			hit = true;
	return hit;
}

bool Snake::touchFood(std::vector<SnakeFood>& food)
{
	for (SnakeFood& f : food)
		if (head.distToEntity(f) - head.getRadius() - f.getRadius() <= 0)
			return true;
	return false;
}

Snake::Snake(sf::Vector2<float> pos)
	:
	head(pos)
{
	cells.push_back(new SnakeCell(&head));
	for (int i = 0; i < 20; i++) cells.push_back(new SnakeCell(cells[i]));
	std::cout << "snake parts size: " << cells.size() + 1 << "\n";

}

Snake::Snake(sf::Vector2<float> pos, sf::Vector2<float> speed)
	:
	head(pos, speed)
{
	cells.push_back(new SnakeCell(&head));
	for (int i = 0; i < 20; i++) cells.push_back(new SnakeCell(cells[i]));
	std::cout << "snake parts size: " << cells.size() + 1 << "\n";
}

Snake::~Snake()
{

}

void Snake::update(float deltaTime)
{
	if (hitSelf())
		head.getSpeed() = { 0, 0 };
	head.update(deltaTime);
	for (auto& e : cells)
		e->update(deltaTime);
	
}

void Snake::draw(sf::RenderTarget * target)
{
	head.draw(target);
	for (SnakeCell* cell : cells)
		cell->draw(target);
}
