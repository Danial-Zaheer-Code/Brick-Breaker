#pragma once
#include<algorithm>
#include <SFML/Graphics.hpp>
#include"Enums.h"

using namespace sf;
using namespace std;

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
		player = RectangleShape(Vector2f(65.f, 6.f));
		player.setPosition(position);
		player.setFillColor(Color::Green);
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

	CollisionSide hasTouchedBall(const Vector2f circleCenter, const float radius) const
	{
		FloatRect playerBounds = player.getGlobalBounds();
		float closestX = max(playerBounds.left, min(circleCenter.x, playerBounds.left + playerBounds.width));
		float closestY = max(playerBounds.top, min(circleCenter.y, playerBounds.top + playerBounds.height));

		float distanceX = circleCenter.x - closestX;
		float distanceY = circleCenter.y - closestY;
		float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

		if (distanceSquared < (radius * radius)) {
			float overlapLeft = circleCenter.x - playerBounds.left;
			float overlapRight = (playerBounds.left + playerBounds.width) - circleCenter.x;
			float overlapTop = circleCenter.y - playerBounds.top;
			float overlapBottom = (playerBounds.top + playerBounds.height) - circleCenter.y;

			float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

			CollisionSide side = CollisionSide::NONE;
			if (minOverlap == overlapLeft) side = CollisionSide::LEFT;
			else if (minOverlap == overlapRight) side = CollisionSide::RIGHT;
			else if (minOverlap == overlapTop) side = CollisionSide::TOP;
			else if (minOverlap == overlapBottom) side = CollisionSide::BOTTOM;

			return side;
		}

		return CollisionSide::NONE;
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
