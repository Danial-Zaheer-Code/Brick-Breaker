#pragma once
#include "GameObjectCreator.h"
using namespace sf;

class GameRunner
{
public:
	GameRunner(): window(sf::VideoMode(1000, 600), "SFML Test")
	{
		ball = GameObjectCreator::createBall(Vector2f(200,200));
		player = GameObjectCreator::createPlayer(Vector2f(300,200));
	}
	~GameRunner() = default;

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

