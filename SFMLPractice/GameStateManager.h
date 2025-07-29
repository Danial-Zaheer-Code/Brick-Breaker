#pragma once
#include"MoveableObjectManager.h"
#include"LevelManager.h"
#include "CollisionTypes.h"
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

    GameState updateState() {
        moveableObjectManager.handlePlayerMovement();


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