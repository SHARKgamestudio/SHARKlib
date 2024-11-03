#pragma once

#pragma region Local Dependencies

#include "GraphicComponent.h"

#pragma endregion

namespace Graphics {
	class ProgressBar : public GraphicComponent {
	public:
		int value;

		ProgressBar(int x, int y, int width, int height, int fg_color = Blue, int bg_color = Black);
		ProgressBar(Vector2 position, Vector2 size, int fg_color = Blue, int bg_color = Black);

		void Draw() override;
		void UpdateValue(int value);
	};
}