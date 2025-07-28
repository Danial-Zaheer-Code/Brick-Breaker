#pragma once
#include"MoveableObjectManager.h"

class GameRunner
{
public:
	GameRunner() : window(sf::VideoMode(1000, 800), "SFML Test"), moveableObjectManager(window.getSize()){}
	~GameRunner() = default;

	void run()
	{
		while (window.isOpen()) {
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}
		
			moveableObjectManager.handlePlayerMovement();
			if(!moveableObjectManager.updateBallMovement()) {
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
		moveableObjectManager.drawMoveableObjects(window);
		window.display();
	}


private:
	RectangleShape level[5][5];
	CircleShape ball;
	RectangleShape player;
	RenderWindow window;
	MoveableObjectManager moveableObjectManager;
};

