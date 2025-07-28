#pragma once
#include"GameStateManager.h"

class GameRunner
{
public:
	GameRunner() : 
		window(sf::VideoMode(1000, 800), "SFML Test"), gameStateManager(window.getSize()){}
	~GameRunner() = default;

	void run()
	{
		while (window.isOpen()) {
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
			}

			GameState updatedState = gameStateManager.updateState();

			if (updatedState == GameState::GAME_OVER)
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

		/*for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				window.draw(level[i][j]);
			}
		}*/
		gameStateManager.drawState(window);
		window.display();
	}


private:
	RenderWindow window;
	GameStateManager gameStateManager;
};

