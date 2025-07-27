#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class GameObjectCreator
{
public:
	static RectangleShape createRectangle(Vector2f size, Vector2f position, Color color)
	{
		RectangleShape rect(size);
		rect.setFillColor(color);
		rect.setPosition(position);
		return rect;
	}

	static CircleShape createBall()
	{
		CircleShape ball = CircleShape(7.f);
		ball.setFillColor(Color::Red);
		ball.setPosition(300.f, 300.f);
		return ball;
	}
};


class GameRunner
{
public:
	GameRunner(): window(sf::VideoMode(1000, 600), "SFML Test")
	{
		ball = GameObjectCreator::createBall();
		player = GameObjectCreator::createRectangle(Vector2f(65.f, 6.f), Vector2f(100.f, 100.f), Color::Green);
	}
	~GameRunner() = default;

private:
	void run()
	{
		while (window.isOpen()) {
			Event event;

			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}
			renderScreen();
		}
	}

private:
	void renderScreen()
	{
		window.clear(Color::Black);

		/*for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				window.draw(level[i][j]);
			}
		}*/

		window.draw(ball);
		window.draw(player);
		window.display();
	}


private:
	RectangleShape level[5][5];
	CircleShape ball;
	RectangleShape player;
	RenderWindow window;
};

