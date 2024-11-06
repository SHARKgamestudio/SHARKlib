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
#include "Char.h"

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

	Canvas::Canvas() : GraphicComponent(0, 0, 0, 0) {
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

		Console::SetCursorLocation(position.x + (x * 2), position.y + y);
		cout << CL_BACKGROUND << color << "m" << "  " << CL_RESET;
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
	
	void Canvas::DrawSpritesheet(Sprite* sprite, int x, int y, int columns, int rows, int index) {
		int i = 0, j = 0;

		int width = sprite->resolution.x / columns;
		int height = sprite->resolution.y / rows;

		int color_x = index % columns;
		int color_y = (index - color_x) / columns;

		int count = (width * color_x) + ((sprite->resolution.x * height) * color_y);

		while (i < height) {
			while (j < width) {
				this->SetPixel(x + j, y + i, sprite->colors.Get(count));
				j++;
				count++;
			}
			count += sprite->resolution.x - width;
			
			j = 0;
			i++;
		}
	}
	void Canvas::DrawSpritesheet(Sprite* sprite, Vector2 position, Vector2 split, int index) {
		DrawSpritesheet(sprite, position.x, position.y, split.x, split.y, index);
	}

	void Canvas::DrawString(Sprite* font, int x, int y, const char* text) {
		int length = Char::GetLength(text);
		for (int i = 0; i < length; i++) {
			if (text[i] != ' ') {
				int index = 39;
				switch (text[i]) {
				case 'A':
					index = 0;
					break;
				case 'B':
					index = 1;
					break;
				case 'C':
					index = 2;
					break;
				case 'D':
					index = 3;
					break;
				case 'E':
					index = 4;
					break;
				case 'F':
					index = 5;
					break;
				case 'G':
					index = 6;
					break;
				case 'H':
					index = 7;
					break;
				case 'I':
					index = 8;
					break;
				case 'J':
					index = 9;
					break;
				case 'K':
					index = 10;
					break;
				case 'L':
					index = 11;
					break;
				case 'M':
					index = 12;
					break;
				case 'N':
					index = 13;
					break;
				case 'O':
					index = 14;
					break;
				case 'P':
					index = 15;
					break;
				case 'Q':
					index = 16;
					break;
				case 'R':
					index = 17;
					break;
				case 'S':
					index = 18;
					break;
				case 'T':
					index = 19;
					break;
				case 'U':
					index = 20;
					break;
				case 'V':
					index = 21;
					break;
				case 'W':
					index = 22;
					break;
				case 'X':
					index = 23;
					break;
				case 'Y':
					index = 24;
					break;
				case 'Z':
					index = 25;
					break;
				case '0':
					index = 26;
					break;
				case '1':
					index = 27;
					break;
				case '2':
					index = 28;
					break;
				case '3':
					index = 29;
					break;
				case '4':
					index = 30;
					break;
				case '5':
					index = 31;
					break;
				case '6':
					index = 32;
					break;
				case '7':
					index = 33;
					break;
				case '8':
					index = 34;
					break;
				case '9':
					index = 35;
					break;
				case '-':
					index = 36;
					break;
				case 'x':
					index = 37;
					break;
				case '!':
					index = 38;
					break;
				default:
					break;
				}
				DrawSpritesheet(font, x + (i * 8), y, 8, 5, index);
			}
		}
	}
}