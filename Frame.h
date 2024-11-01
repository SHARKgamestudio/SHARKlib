#pragma once

#pragma region Local Dependencies

#include "GraphicComponent.h"

#pragma endregion

class Frame : public GraphicComponent {
public:
	Vector2 size;

	Frame(int width, int height, Color color);
	Frame(Vector2 size, Color color);
	Frame(int width, int height, int x = 0, int y = 0, Color color = White);
	Frame(Vector2 size, Vector2 position = Vector2(0, 0), Color color = White);

	virtual void Draw();
};