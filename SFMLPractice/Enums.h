#pragma once
enum class CollisionSide {
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	NONE
};

enum class ObjectType
{
	PLAYER = 0,
	BREAKABLE_BLOCK = 100,
	UNBREAKABLE_BLOCK = 200,
	NONE
};
struct CollidedObject {
	ObjectType type;
	CollisionSide side;
};