#pragma once

#pragma region Local Dependencies

#include "GraphicComponent.h"
#include "IntArray.h"

#pragma endregion

namespace Graphics {
	struct Sprite {
	public:
		Vector2 resolution;
		IntArray colors;

		Sprite();
		Sprite(const char* path);

		void LoadFromFile(const char* path);
	};

	class Canvas : GraphicComponent {
	public:
		Canvas(int x, int y, int width, int height);
		Canvas(Vector2 position, Vector2 size);

		void SetPixel(int x, int y, int color);
		void SetPixel(Vector2 location, int color);

		void DrawSprite(Sprite* sprite, int x, int y);
		void DrawSprite(Sprite* sprite, Vector2 location);

		void DrawSpritesheet(Sprite* sprite, int columns, int rows, int index);
	};
}