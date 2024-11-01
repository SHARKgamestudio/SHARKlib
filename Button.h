#pragma once

#pragma region Local Dependencies

#include "BString.h"
#include "Frame.h"

#pragma endregion

class Button : public Frame {
public:
	String label;

	Button(const char* label, Vector2 size);
	Button(const char* label, int width, int height, int x = 0, int y = 0);
	Button(const char* label, Vector2 size, Vector2 position = Vector2(0, 0));

	void Draw() override;
};