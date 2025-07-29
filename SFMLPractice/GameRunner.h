#pragma once
#include"GameLogicManager.h"

class GameRunner
{
public:
	GameRunner() : 
		window(sf::VideoMode(1000, 800), "SFML Test"), gameLogicManager(window.getSize()){}
	~GameRunner() = default;

	void run()
	{
		while (window.isOpen()) {
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}

			GameState updatedState = gameLogicManager.handleGameLogic();

			if (updatedState == GameState::GAME_OVER)
			{
				window.close();
				return;
			}
			else if(updatedState == GameState::WON)
			{
				window.close();
				return;
			}

			renderScreen();
		}
	}

private:
	void renderScreen()
	{
		window.clear(Color::Black);
		gameLogicManager.drawGameObjects(window);
		window.display();
	}


private:
	RenderWindow window;
	GameLogicManager gameLogicManager;
};

