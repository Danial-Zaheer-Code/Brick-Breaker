#pragma once
#include "GameObjectFactory.h"


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
				player.move(-0.3f, 0.f);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (player.getPosition().x + player.getSize().x < windowSize.x) {
				player.move(0.3f, 0.f);
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

private:
	CircleShape ball;
	RectangleShape player;
	Vector2f ballVelocity = Vector2f(0.1f, 0.1f);
	const Vector2f windowSize;
};


