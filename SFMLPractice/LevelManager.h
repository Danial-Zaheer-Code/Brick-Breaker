#pragma once
#include"GameObjectFactory.h"
#include<vector>
using std::vector;


enum class BlockType
{
	Breakable,
	Unbreakable,
	None
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

	
private:
	vector<RectangleShape> blocks;
};
