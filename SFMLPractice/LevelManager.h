#pragma once
#include<algorithm>
#include"GameObjectFactory.h"
#include"Enums.h"
#include<vector>
using namespace std;

class CollisionDetector 
{
public:
	static CollidedObject hasCollided(const FloatRect blockBounds, const Vector2f circleCenter, float radius)
	{
		/*float closestX = max(blockBounds.left, min(circleCenter.x, blockBounds.left + blockBounds.width));
		float closestY = max(blockBounds.top, min(circleCenter.y, blockBounds.top + blockBounds.height));

		float distanceX = circleCenter.x - closestX;
		float distanceY = circleCenter.y - closestY;
		float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

		if (distanceSquared < (radius * radius)) 
		{
			float overlapLeft = circleCenter.x - blockBounds.left;
			float overlapRight = (blockBounds.left + blockBounds.width) - circleCenter.x;
			float overlapTop = circleCenter.y - blockBounds.top;
			float overlapBottom = (blockBounds.top + blockBounds.height) - circleCenter.y;

			float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

			CollisionSide side = CollisionSide::NONE;
			if (minOverlap == overlapLeft) side = CollisionSide::LEFT;
			else if (minOverlap == overlapRight) side = CollisionSide::RIGHT;
			else if (minOverlap == overlapTop) side = CollisionSide::TOP;
			else if (minOverlap == overlapBottom) side = CollisionSide::BOTTOM;

			if (block->getFillColor() == Color::White) 
			{
				block = blocks.erase(block);
				return { ObjectType::BREAKABLE_BLOCK, side };
			}
			else if (block->getFillColor() == Color::Blue) 
			{
				return { ObjectType::UNBREAKABLE_BLOCK, side };
			}
		}
		return { ObjectType::NONE, CollisionSide::NONE };*/
	}
};

class BlockType
{
	BlockType(ObjectType type)
	{

	}
	void draw(RenderTarget& window)
	{
		window.draw(block);
	}
private:
	ObjectType type;
	RectangleShape block;
};

class LevelManager
{
public:
	LevelManager()
	{
		blocks.reserve(2);

		blocks.push_back(BlockFactory::create(Vector2f(400, 100),ObjectType::BREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(500, 100), ObjectType::UNBREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(600, 100), ObjectType::BREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(700, 100), ObjectType::UNBREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(300, 100), ObjectType::BREAKABLE_BLOCK));

		blocks.push_back(BlockFactory::create(Vector2f(450, 100), ObjectType::UNBREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(550, 100), ObjectType::BREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(650, 100), ObjectType::UNBREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(350, 100), ObjectType::BREAKABLE_BLOCK));
		blocks.push_back(BlockFactory::create(Vector2f(750, 100), ObjectType::UNBREAKABLE_BLOCK));
	}

	CollidedObject detectCollision(const Vector2f circleCenter, float radius) {
		for (auto block = blocks.begin(); block != blocks.end(); block++) {
			FloatRect blockBounds = block->getGlobalBounds();

			float closestX = max(blockBounds.left, min(circleCenter.x, blockBounds.left + blockBounds.width));
			float closestY = max(blockBounds.top, min(circleCenter.y, blockBounds.top + blockBounds.height));

			float distanceX = circleCenter.x - closestX;
			float distanceY = circleCenter.y - closestY;
			float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

			if (distanceSquared < (radius * radius)) {
				float overlapLeft = circleCenter.x - blockBounds.left;
				float overlapRight = (blockBounds.left + blockBounds.width) - circleCenter.x;
				float overlapTop = circleCenter.y - blockBounds.top;
				float overlapBottom = (blockBounds.top + blockBounds.height) - circleCenter.y;

				float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

				CollisionSide side = CollisionSide::NONE;
				if (minOverlap == overlapLeft) side = CollisionSide::LEFT;
				else if (minOverlap == overlapRight) side = CollisionSide::RIGHT;
				else if (minOverlap == overlapTop) side = CollisionSide::TOP;
				else if (minOverlap == overlapBottom) side = CollisionSide::BOTTOM;

				if (block->getFillColor() == Color::White) {
					block = blocks.erase(block);
					return { ObjectType::BREAKABLE_BLOCK, side };
				}
				else if (block->getFillColor() == Color::Blue) {
					return { ObjectType::UNBREAKABLE_BLOCK, side };
				}
			}
		}
		return { ObjectType::NONE, CollisionSide::NONE };
	}
	void drawLevel(RenderTarget& window)
	{
		for (const auto& block : blocks)
		{
			window.draw(block);
		}
	}

	int remainingBlocks() const
	{
		return blocks.size();
	}
private:
	vector<RectangleShape> blocks;
};
