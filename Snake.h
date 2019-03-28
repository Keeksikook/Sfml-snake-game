#pragma once
#include "State.h"

class SnakeHead :
	public Entity
{
private:
	sf::CircleShape shape;
protected:

public:
	SnakeHead(sf::Vector2<float> pos);
	SnakeHead(sf::Vector2<float> pos, sf::Vector2<float> speed);
	SnakeHead(Entity* e);
	~SnakeHead();

	void draw(sf::RenderTarget* target) { target->draw(shape); }
	void update(float deltaTime)override;
	void steer(float angle); /* [-1 ; 1]*/
	float distToEntity(Entity& e);
	float getRadius() { return shape.getRadius(); }
	virtual sf::Vector2<float> getPos() const override { return pos; }
	sf::Vector2<float>& getSpeed() { return speed; }
};

class SnakeCell :
	public Entity
{
private:
	Entity* followTarget;
	sf::CircleShape  shape;
	void follow();
public:
	SnakeCell(Entity* followTarget);
	virtual ~SnakeCell();
	void update(float deltaTime)override;
	void draw(sf::RenderTarget* target) { target->draw(shape); }
	float getRadius() { return shape.getRadius(); }
	sf::Vector2<float> getPos() const override { return pos; }
	sf::Vector2<float> getSpeed() const override { return speed; }
};

class SnakeFood :
	public Entity
{
	sf::CircleShape shape;
public:
	SnakeFood(sf::Vector2<float> pos, float radius);
	~SnakeFood();

	void draw(sf::RenderTarget* target) { target->draw(shape); }
	float getRadius() { return shape.getRadius(); }
};

class Snake
{
private:
	SnakeHead head;
	std::vector<SnakeCell*> cells;
	bool hitSelf();
	bool touchFood(std::vector<SnakeFood>& food);
public:
	Snake(sf::Vector2<float> pos);
	Snake(sf::Vector2<float> pos, sf::Vector2<float> speed);
	~Snake();
	void update(float deltaTime);
	void draw(sf::RenderTarget* target);
	void steer(float angle) { head.steer(angle); }

};