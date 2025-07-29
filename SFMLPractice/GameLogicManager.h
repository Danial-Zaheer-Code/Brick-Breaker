#pragma once
#include "BallManager.h"
#include "PlayerManager.h"
#include "LevelManager.h"
enum GameState
{
	MAIN_MENU,
	PLAYING,
	GAME_OVER,
	WON
};

class GameLogicManager
{
public:
	GameLogicManager(Vector2u _windowSize) : playerManager(Vector2f(460.f, 600.f), _windowSize), ballManager(Vector2f(playerManager.getPlayerPosition().x + playerManager.getPlayerSize().x / 2, playerManager.getPlayerPosition().y), _windowSize) {}

	~GameLogicManager() = default;
	
	void drawGameObjects(RenderTarget& window)
	{
		ballManager.drawBall(window);
		playerManager.drawPlayer(window);
		levelManager.drawLevel(window);
	}


	GameState handleGameLogic()
	{
		handlePlayerMovement();
		return updateBallMovement();
	}

private:
	void handlePlayerMovement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			playerManager.movePlayer(PlayerManager::PlayerDirection::Left);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			playerManager.movePlayer(PlayerManager::PlayerDirection::Right);
		}
	}

	GameState updateBallMovement()
	{
		if (ballManager.hasBallTouchedMainWindowSideWays())
		{
			ballManager.changeBallVelocityHorizontally();
		}

		if (ballManager.hasBallTouchedMainWindowTop())
		{
			ballManager.changeBallVelocityVertically();
		}

		if (ballManager.hasBallTouchedMainWindowBottom())
		{
			return GAME_OVER;
		}


		CollisionSide side = playerManager.hasTouchedBall(ballManager.getBallPosition(), ballManager.getBallRadius());
		if(side == CollisionSide::LEFT || side == CollisionSide::RIGHT)
		{
			ballManager.changeBallVelocityHorizontally();
		}
		else if (side == CollisionSide::TOP || side == CollisionSide::BOTTOM)
		{
			ballManager.changeBallVelocityVertically();
		}
		else
		{

			CollidedObject collision = levelManager.detectCollision(ballManager.getBallPosition(), ballManager.getBallRadius());

			if (collision.side != CollisionSide::NONE) {
				if (levelManager.remainingBlocks() <= 0) {
					return WON;
				}

				if (collision.side == CollisionSide::LEFT || collision.side == CollisionSide::RIGHT)
				{
					ballManager.changeBallVelocityHorizontally();
				}
				else
				{
					ballManager.changeBallVelocityVertically();
				}
			}
		}
		ballManager.moveBall();
		return PLAYING;
	}
private:
	PlayerManager playerManager;
	BallManager ballManager;
	LevelManager levelManager;
};


