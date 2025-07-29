#pragma once
#include "GameObjectFactory.h"
class PlayerManager
{
public:
	enum PlayerDirection
	{
		Left,
		Right
	};


public:
	PlayerManager(Vector2f position, Vector2u _windowSize) : windowSize(_windowSize)
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

	Vector2f getPlayerPosition() const
	{
		return player.getPosition();
	}

	Vector2f getPlayerSize() const
	{
		return player.getSize();
	}
private:

	RectangleShape player;
	Vector2f playerVelocity = Vector2f(0.5f, 0.f);
	const Vector2u windowSize;
};
