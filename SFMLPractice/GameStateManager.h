#pragma once
#include"GameLogicManager.h"
#include"LevelManager.h"
#include "CollisionTypes.h"

class GameStateManager
{
public:
	GameStateManager(Vector2u windowSize) : gameLogicManager(windowSize) {}
	~GameStateManager() = default;

    GameState updateState() {

		return gameLogicManager.handleGameLogic();
        /*moveableObjectManager.handlePlayerMovement();


        Vector2f ballCenter = moveableObjectManager.getBallPosition();
		float ballRadius = 7.f;

        BlockCollision collision = levelManager.detectCollision(ballCenter, ballRadius);

        if (collision.type == BlockType::NONE) {
            if (!moveableObjectManager.updateBallMovement()) {
                return GAME_OVER;
            }
        }
        else if (collision.type == BlockType::BREAKABLE) {
            if (levelManager.remainingBlocks() <= 0) {
                return WON;
            }
            moveableObjectManager.ballHasTouchedABlock(collision.side);
        }
        else if (collision.type == BlockType::UNBREAKABLE) {
            moveableObjectManager.ballHasTouchedABlock(collision.side);
        }

        return PLAYING;*/
    }

	void drawState(RenderTarget& window)
	{
		gameLogicManager.drawGameObjects(window);
	}
private:
	GameLogicManager gameLogicManager;
	
};