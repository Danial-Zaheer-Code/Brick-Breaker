#pragma once
#include "GameObjectCreator.h"
using namespace sf;
extern Vector2f ballVelocity;
class GameRunner
{
public:
	GameRunner(): window(sf::VideoMode(1000, 800), "SFML Test")
	{
		float ballSize = 7.f;
		Vector2f playerPosition(460.f, 700.f);
		Vector2f playerSize(65.f, 6.f);
		player = GameObjectCreator::createPlayer(playerPosition);
        ball = GameObjectCreator::createBall(
            Vector2f(playerPosition.x + playerSize.x / 2, playerPosition.y-ballSize-ballSize)
        );

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
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				player.move(-0.1f, 0.f);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				player.move(0.1f, 0.f);
			}
			ball.move(ballVelocity);
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

