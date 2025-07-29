#pragma once
#include"GameObjectFactory.h"
#include<vector>
using std::vector;


enum class BlockType
{
	BREAKABLE,
	UNBREAKABLE,
	NONE
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
				if (block->getFillColor() == Color::White) // Assuming breakable blocks are red
				{
					block = blocks.erase(block); // Remove the block if it's breakable
					return BlockType::BREAKABLE;
				}
				else if (block->getFillColor() == Color::Blue) // Assuming unbreakable blocks are blue
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
