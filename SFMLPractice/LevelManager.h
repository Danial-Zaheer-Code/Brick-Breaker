#pragma once
#include"GameObjectFactory.h"
#include<vector>
#include"CollisionTypes.h"
using namespace std;
using std::vector;


enum class BlockType
{
	BREAKABLE,
	UNBREAKABLE,
	NONE
};
struct BlockCollision {
	BlockType type;
	CollisionSide side;
};

class LevelManager
{
public:
	LevelManager()
	{
		blocks.reserve(2);

		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(400, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(500, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(600, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(700, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(300, 100)));

		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(450, 100)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(550, 100)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(650, 100)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(350, 100)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(750, 100)));
	}

	BlockCollision detectCollision(const Vector2f& circleCenter, float radius) {
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
					return { BlockType::BREAKABLE, side };
				}
				else if (block->getFillColor() == Color::Blue) {
					return { BlockType::UNBREAKABLE, side };
				}
			}
		}
		return { BlockType::NONE, CollisionSide::NONE };
	}
	void drawLevel(RenderTarget& window)
	{
		for (const auto& block : blocks)
		{
			window.draw(block);
		}
	}

	BlockType getBlockType(const Vector2f& position)
	{
		for (auto block = blocks.begin(); block != blocks.end(); block++)
		{
			if (block->getGlobalBounds().contains(position))
			{
				if (block->getFillColor() == Color::White) 
				{
					block = blocks.erase(block); 
					return BlockType::BREAKABLE;
				}
				else if (block->getFillColor() == Color::Blue)
				{
					return BlockType::UNBREAKABLE;
				}
			}
		}

		return BlockType::NONE;
	}

	int remainingBlocks() const
	{
		return blocks.size();
	}
private:
	vector<RectangleShape> blocks;
};
