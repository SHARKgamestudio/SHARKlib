#pragma once

#pragma region Local Dependencies

#include "Vector.h"

#pragma endregion

class Vector2 : public Vector {
public:
	int x, y;
	int magnitude;

	Vector2();
	Vector2(int x, int y);
};