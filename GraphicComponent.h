#pragma once

#pragma region Local Dependencies

#include "Color.h"
#include "Vector2.h"

#pragma endregion

namespace Graphics {
	class GraphicComponent {
	public:
		Vector2 position;
		Vector2 size;

		int fg_color;
		int bg_color;

		GraphicComponent(int x, int y, int width, int height, int fg_color = White, int bg_color = Black);
		GraphicComponent(Vector2 position, Vector2 size, int fg_color = White, int bg_color = Black);
	};
}