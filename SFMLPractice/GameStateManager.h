#pragma once
#include"MoveableObjectManager.h"

enum GameState
{
	MAIN_MENU,
	PLAYING,
	GAME_OVER
};

class GameStateManager
{
public:
	GameStateManager(Vector2u windowSize) : moveableObjectManager(windowSize) {}
	~GameStateManager() = default;

	GameState updateState()
	{
		moveableObjectManager.handlePlayerMovement();
		if (!moveableObjectManager.updateBallMovement()) {
			return GAME_OVER;
		}

		return PLAYING;
	}

	void drawState(RenderTarget& window)
	{
		moveableObjectManager.drawMoveableObjects(window);
	}
private:
	MoveableObjectManager moveableObjectManager;
};