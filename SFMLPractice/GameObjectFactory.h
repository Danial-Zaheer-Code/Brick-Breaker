#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#pragma once
#include"Enums.h"

class BlockFactory 
{
public:
	static RectangleShape create(Vector2f position, ObjectType type)
	{
		switch (type)
		{
		case ObjectType::BREAKABLE_BLOCK:
			return createBlock(Vector2f(45.f, 15.f), position, Color::White);
			break;
		case ObjectType::UNBREAKABLE_BLOCK:
			return createBlock(Vector2f(45.f, 15.f), position, Color::Blue);
			break;
		default:
			throw new invalid_argument("Wrong Block type");
		} 
	}

private:
	static RectangleShape createBlock(Vector2f size, Vector2f position, Color color)
	{
		RectangleShape rect(size);
		rect.setFillColor(color);
		rect.setPosition(position);
		return rect;
	}

};


