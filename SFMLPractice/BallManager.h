#pragma once
#include "GameObjectFactory.h"

class BallManager
{
public:
	BallManager(Vector2f position, Vector2u _windowSize) :windowSize(_windowSize)
	{
		position.y = position.y - radius - radius;
		ball = GameObjectFactory::createBall(position);
	}

	void changeBallVelocityHorizontally()
	{
		ballVelocity.x = -ballVelocity.x;
	}

	void changeBallVelocityVertically()
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

	float getBallRadius() const
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
	Vector2f ballVelocity = Vector2f(0.5f, -0.5f);
	const float radius = 7.f;
	const Vector2u windowSize;

};
