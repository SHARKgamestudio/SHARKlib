#include "Canvas.h"

#pragma region External Dependencies

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#pragma endregion

#pragma region Local Dependencies

#include "Console.h"
#include "Color.h"

#pragma endregion

using namespace std;

namespace Graphics {
	Sprite::Sprite() {
		this->resolution = Vector2(0, 0);
		this->colors = IntArray();
	}
	Sprite::Sprite(const char* path) {
		this->resolution = Vector2(0, 0);
		this->colors = IntArray();

		this->LoadFromFile(path);
	}

	void Sprite::LoadFromFile(const char* path) {
		ifstream file(path);
		
		if (!file.is_open()) {
			cout << "Error opening the file!";
			return;
		}

		string str;

		int count = 0;
		while (getline(file, str)) {
			if (count == 0) { resolution.x = stoi(str); }
			if (count == 1) { resolution.y = stoi(str); }
			if (count > 1) {
				int r, g, b;
				char discard;

				std::stringstream ss(str);
				ss >> discard >> r >> discard >> g >> discard >> b >> discard;

				int color = RGBToAnsi(r, g, b);
				colors.Add(color);
			}
			count++;
		}
	}

	Canvas::Canvas(int x, int y, int width, int height) : GraphicComponent(x, y, width, height) {
	}
	Canvas::Canvas(Vector2 position, Vector2 size) : GraphicComponent(position, size) {
	}

	void Canvas::SetPixel(int x, int y, int color) {
		if (x < 0)
			return;

		if (x > position.x + size.x)
			return;

		if (y < 0)
			return;

		if (y > position.y + size.y)
			return;

		Console::SetCursorLocation(position.x + x, position.y + y);
		cout << CL_BACKGROUND << color << "m" << " " << CL_RESET;
	}
	void Canvas::SetPixel(Vector2 location, int color) {
		SetPixel(location.x, location.y, color);
	}

	void Canvas::DrawSprite(Sprite* sprite, int x, int y) {
		int index = 0;
		for (int i = 0; i < sprite->resolution.y; i++) {
			for (int j = 0; j < sprite->resolution.x; j++) {
				this->SetPixel(x + j, y + i, sprite->colors.Get(index));
				index++;
			}
		}
	}
	void Canvas::DrawSprite(Sprite* sprite, Vector2 location) {
		this->DrawSprite(sprite, location.x, location.y);
	}
	
	void Canvas::DrawSpritesheet(Sprite* sprite, int columns, int rows, int index) {
		int i = 0, j = 0;

		int width = sprite->resolution.x / columns;
		int height = sprite->resolution.y / rows;

		int count = width * index;

		while (i < height) {
			while (j < width) {
				this->SetPixel(j, i, sprite->colors.Get(count));
				j++;
				count++;
			}
			std::cout << count;
			j = 0;
			i++;
			count += sprite->resolution.x - width;
		}

	}
}