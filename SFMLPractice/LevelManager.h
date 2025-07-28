#pragma once
#include"GameObjectFactory.h"
#include<vector>
using std::vector;
class LevelManager
{
public:
	LevelManager()
	{
		blocks.reserve(20);

		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(10, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(20, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(30, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(40, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(50, 100)));

		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(5, 200)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(15, 200)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(25, 200)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(35, 200)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(45, 200)));
	}



private:
	vector<RectangleShape> blocks;
};
