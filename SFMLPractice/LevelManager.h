#pragma once
#include"GameObjectFactory.h"
#include<vector>
using std::vector;
class LevelManager
{
public:
	LevelManager()
	{
		blocks.reserve(2);

		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(10, 100)));
		/*blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(25, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(40, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(55, 100)));
		blocks.push_back(GameObjectFactory::createBreakableBlock(Vector2f(70, 100)));*/

		//blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(5, 120)));
		/*blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(20, 120)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(35, 120)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(50, 120)));
		blocks.push_back(GameObjectFactory::createUnbreakableBlock(Vector2f(65, 120)));*/
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
