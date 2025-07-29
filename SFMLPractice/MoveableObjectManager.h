#pragma once
#include "GameObjectFactory.h"
#include "CollisionTypes.h"
class BallManager
{
public:
	BallManager(Vector2f position, Vector2u _windowSize):windowSize(_windowSize)
	{
		position.y = position.y - radius - radius;
		ball = GameObjectFactory::createBall(position);
	}

	void changeBallPostionHorizontally()
	{
		ballVelocity.x = -ballVelocity.x;
	}

	void changeBallPositionVertically()
	{
		ballVelocity.y = -ballVelocity.y;
	}

	void moveBall()
	{
		ball.move(ballVelocity);
	}

	Vector2f getBallPosition() const
	{
		return ball.getPosition();
	}

	float getBallRadius()
	{
		return ball.getRadius();
	}

	void drawBall(RenderTarget& window)
	{
		window.draw(ball);
	}

	bool hasTouchedMainWindowSideWays() const
	{
		Vector2f ballPosition = ball.getPosition();
		float radius = ball.getRadius();
		return (ballPosition.x + radius >= windowSize.x || ballPosition.x <= 0);
	}

	bool hasTouchedMainWindowTop() const
	{
		Vector2f ballPosition = ball.getPosition();
		float radius = ball.getRadius();
		return (ballPosition.y <= 0);
	}

	bool hasTouchedMainWindowBottom() const
	{
		Vector2f ballPosition = ball.getPosition();
		float radius = ball.getRadius();
		return (ballPosition.y + radius >= windowSize.y);
	}
	
private:
	CircleShape ball;
	Vector2f ballVelocity = Vector2f(0.5f, 0.5f);
	const float radius = 7.f;
	const Vector2u windowSize;
	
};



class playerManager
{
public:
	enum PlayerDirection
	{
		Left,
		Right
	};


public:
	playerManager(Vector2f position, Vector2u _windowSize) : windowSize(_windowSize)
	{
		player = GameObjectFactory::createPlayer(position);
	}

	void movePlayer(PlayerDirection direction)
	{
		if (direction == PlayerDirection::Left && player.getPosition().x > 0.f) 
		{
				player.move(-playerVelocity.x, 0.f);
		}
		else if (direction == PlayerDirection::Right && player.getPosition().x + player.getSize().x < windowSize.x) 
		{
				player.move(playerVelocity.x, 0.f);
		}
	}

	bool hasTouchedBall(Vector2f ballPosition, float ballRadius) const
	{
		Vector2f playerPosition = player.getPosition();
		return (ballPosition.y + ballRadius >= playerPosition.y &&
				ballPosition.x + ballRadius >= playerPosition.x &&
				ballPosition.x <= playerPosition.x + player.getSize().x);
	}

	void drawPlayer(RenderTarget& window)
	{
		window.draw(player);
	}
private:
	
	RectangleShape player;
	Vector2f playerVelocity = Vector2f(0.5f, 0.f);
	const Vector2u windowSize;
};

class MoveableObjectManager
{
public:
	MoveableObjectManager(Vector2u _windowSize) : windowSize(_windowSize)
	{
		Vector2f playerPosition(460.f, 600.f);
		player = GameObjectFactory::createPlayer(playerPosition);

		float ballSize = 7.f;
		Vector2f playerSize = player.getSize();
		ball = GameObjectFactory::createBall(
			Vector2f(playerPosition.x + playerSize.x / 2, playerPosition.y - ballSize - ballSize)
		);

	}

	~MoveableObjectManager() = default;

	void handlePlayerMovement()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (player.getPosition().x > 0.f) {
				player.move(-0.6f, 0.f);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (player.getPosition().x + player.getSize().x < windowSize.x) {
				player.move(0.6f, 0.f);
			}
		}
	}

	bool updateBallMovement()
	{
		Vector2f ballPosition = ball.getPosition();
		float radius = ball.getRadius();

		if (ballPosition.x + radius >= windowSize.x || ballPosition.x <= 0) {
			ballVelocity.x = -ballVelocity.x;
		}
		if (ballPosition.y + radius >= windowSize.y || ballPosition.y <= 0) {
			ballVelocity.y = -ballVelocity.y;
		}
		if (ballPosition.y + radius >= player.getPosition().y && ballPosition.x + radius >= player.getPosition().x && ballPosition.x <= player.getPosition().x + player.getSize().x) {
			ballVelocity.y = -ballVelocity.y;
		}

		if (ballPosition.y + radius >= windowSize.y) {
			return false;
		}

		ball.move(ballVelocity);
		return true;
	}

	void drawMoveableObjects(RenderTarget& window)
	{
		window.draw(ball);
		window.draw(player);
	}
	
	Vector2f getBallPosition() const {
		Vector2f pos = ball.getPosition();
		float radius = ball.getRadius();
		return { pos.x + radius, pos.y + radius };
	}

	void ballHasTouchedABlock(CollisionSide side) {
		if (side == CollisionSide::TOP || side == CollisionSide::BOTTOM) {
			ballVelocity.y = -ballVelocity.y;
		}
		else if (side == CollisionSide::LEFT || side == CollisionSide::RIGHT) {
			ballVelocity.x = -ballVelocity.x;
		}
		ball.move(ballVelocity);
	}
private:
	CircleShape ball;
	RectangleShape player;
	Vector2f ballVelocity = Vector2f(0.5f, 0.5f);
	const Vector2f windowSize;
};


