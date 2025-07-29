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
	BREAKABLE_BLOCK,
	UNBREAKABLE_BLOCK,
	PLAYER,
	NONE
};
struct CollidedObject {
	ObjectType type;
	CollisionSide side;
};