#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class BallManager
{
public:
	BallManager(Vector2f position, Vector2u _windowSize) :windowSize(_windowSize)
	{
		position.y = position.y - radius - radius;
		ball = CircleShape(radius);
		ball.setFillColor(Color::Red);
		ball.setPosition(position);
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

	bool hasBallTouchedMainWindowSideWays() const
	{
		Vector2f ballPosition = ball.getPosition();
		return (ballPosition.x + radius >= windowSize.x || ballPosition.x <= 0);
	}

	bool hasBallTouchedMainWindowTop() const
	{
		Vector2f ballPosition = ball.getPosition();
		return (ballPosition.y <= 0);
	}

	bool hasBallTouchedMainWindowBottom() const
	{
		Vector2f ballPosition = ball.getPosition();
		return (ballPosition.y + radius >= windowSize.y);
	}

private:
	CircleShape ball;
	Vector2f ballVelocity = Vector2f(0.5f, 0.5f);
	const float radius = 7.f;
	const Vector2u windowSize;
};
