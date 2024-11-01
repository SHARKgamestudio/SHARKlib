#pragma once

#pragma region Local Dependencies

#include "Color.h"
#include "Vector2.h"

#pragma endregion

namespace Graphics {
	class GraphicComponent {
	public:
		Vector2 position;
		Color color;

		GraphicComponent(int x, int y, Color = White);
		GraphicComponent(Vector2 position, Color = White);
	};
}