#pragma once

#pragma region Local Dependencies

#include "RichText.h"
#include "Frame.h"

#pragma endregion

namespace Graphics {
	class Button : public Frame {
	public:
		RichText label;

		Button(const char* label, int width, int height, int x, int y);
		Button(const char* label, Vector2 size, Vector2 position);

		void Draw() override;
	};
}