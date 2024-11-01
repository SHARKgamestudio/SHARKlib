#pragma once

#pragma region Local Dependencies

#include "Vector2.h"

#pragma endregion

class Console {
public:
	static void SetFont(int size = 12);
	static void SetCursorVisibility(bool visible);
	static void SetCursorLocation(int x, int y);
	static Vector2 GetSize();
};