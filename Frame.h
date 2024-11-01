#pragma once

#pragma region Local Dependencies

#include "GraphicComponent.h"

#pragma endregion

namespace Graphics {
	class Frame : public GraphicComponent {
	public:
		Frame(int x, int y, int width, int height, int fg_color = White, int bg_color = Black);
		Frame(Vector2 position, Vector2 size, int fg_color = White, int bg_color = Black);

		virtual void Draw();
	};
};