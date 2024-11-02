#pragma once

#pragma region Local Dependencies

#include "RichText.h"
#include "Frame.h"

#pragma endregion

namespace Graphics {
	class Button : public Frame {
	private:
		int current_color;

		int normal_color;
		int highlight_color;
	public:
		RichText label;

		Button(const char* label, int x, int y, int width, int height, int normal_color = White, int highlight_color = Blue);
		Button(const char* label, Vector2 position, Vector2 size, int normal_color = White, int highlight_color = Blue);

		void Draw() override;
		void Highlight() override;
	};
}