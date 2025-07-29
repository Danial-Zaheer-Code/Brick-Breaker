#pragma once
#include "BallManager.h"
#include "PlayerManager.h"
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


	GameState handleGameLogic()
	{
		handlePlayerMovement();


		if (!updateBallMovement())
		{
			return GameState::GAME_OVER;
		}

		return GameState::PLAYING;
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

	bool updateBallMovement()
	{
		if (ballManager.hasTouchedMainWindowSideWays())
		{
			ballManager.changeBallVelocityHorizontally();
		}

		if (ballManager.hasTouchedMainWindowTop())
		{
			ballManager.changeBallVelocityVertically();
		}

		if (playerManager.hasTouchedBall(ballManager.getBallPosition(),ballManager.getBallRadius()))
		{
			ballManager.changeBallVelocityVertically();
		}

		if (ballManager.hasTouchedMainWindowBottom())
		{
			return false;
		}

		ballManager.moveBall();
		return true;
	}

public:
	void drawGameObjects(RenderTarget& window)
	{
		ballManager.drawBall(window);
		playerManager.drawPlayer(window);
	}

private:
	PlayerManager playerManager;
	BallManager ballManager;
};


