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

	Vector2 operator+(Vector2 vector);
	void operator+=(Vector2 vector);
	bool operator!=(Vector2 vector);
};