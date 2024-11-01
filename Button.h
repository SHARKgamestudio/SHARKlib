#pragma once

#pragma region Local Dependencies

#include "RichText.h"
#include "Frame.h"

#pragma endregion

namespace Graphics {
	class Button : public Frame {
	public:
		RichText label;

		Button(const char* label, Vector2 size);
		Button(const char* label, int width, int height, int x = 0, int y = 0);
		Button(const char* label, Vector2 size, Vector2 position = Vector2(0, 0));

		void Draw() override;
	};
}