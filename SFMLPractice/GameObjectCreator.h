#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class GameObjectCreator 
{
public:
	static RectangleShape createbreakableBlock(Vector2f position)
	{
		return createRectangle(Vector2f(40.f, 15.f), position, Color::White);
	}

	static RectangleShape createUnbreakableBlock(Vector2f position)
	{
		return createRectangle(Vector2f(40.f, 15.f), position, Color::Blue);;
	}

	static RectangleShape createPlayer(Vector2f position)
	{
		return createRectangle(Vector2f(65.f, 6.f), position, Color::Green);
	}

private:
	static RectangleShape createRectangle(Vector2f size, Vector2f position, Color color)
	{
		RectangleShape rect(size);
		rect.setFillColor(color);
		rect.setPosition(position);
		return rect;
	}

public:
	static CircleShape createBall(Vector2f position)
	{
		CircleShape ball = CircleShape(7.f);
		ball.setFillColor(Color::Red);
		ball.setPosition(position);
		return ball;
	}
};


