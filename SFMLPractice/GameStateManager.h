#pragma once
#include"MoveableObjectManager.h"
#include"LevelManager.h"

enum GameState
{
	MAIN_MENU,
	PLAYING,
	GAME_OVER,
	WON
};

class GameStateManager
{
public:
	GameStateManager(Vector2u windowSize) : moveableObjectManager(windowSize) {}
	~GameStateManager() = default;

	GameState updateState()
	{
		moveableObjectManager.handlePlayerMovement();

		BlockType blockType = levelManager.getBlockType(moveableObjectManager.getBallPosition());

		if(blockType == BlockType::NONE) {
			if (!moveableObjectManager.updateBallMovement()) {
				return GAME_OVER;
			}
		}
		else if (blockType == BlockType::BREAKABLE && levelManager.remainingBlocks() <= 0)
		{
			return WON;
		}
		else if (blockType == BlockType::BREAKABLE || blockType == BlockType::UNBREAKABLE) {
			moveableObjectManager.ballHasTouchedABlock();
		}
		
		return PLAYING;
	}

	void drawState(RenderTarget& window)
	{
		moveableObjectManager.drawMoveableObjects(window);
		levelManager.drawLevel(window);
	}
private:
	MoveableObjectManager moveableObjectManager;
	LevelManager levelManager;
	
};