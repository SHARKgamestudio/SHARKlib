#include "Frame.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Ascii.h"
#include "RichText.h"
#include "Console.h"

#pragma endregion

using namespace std;

namespace Graphics {
	Frame::Frame(int x, int y, int width, int height, int fg_color, int bg_color) : GraphicComponent(x, y, width, height, fg_color, bg_color) {
	}
	Frame::Frame(Vector2 position, Vector2 size, int fg_color, int bg_color) : GraphicComponent(position, size, fg_color, bg_color) {
	}

	void Frame::Draw() {
		RichText visuals(CHAR_218);

		visuals.SetFGColor(fg_color);

		Console::SetCursorLocation(position.x, position.y);
		cout << visuals;

		visuals = CHAR_196;

		for (int i = 0; i < this->size.x - 2; i++) {
			Console::SetCursorLocation(position.x + i + 1, position.y);
			cout << visuals;
		}

		visuals = CHAR_191;

		Console::SetCursorLocation(position.x + size.x - 1, position.y);
		cout << visuals;

		visuals = CHAR_179;

		for (int i = 0; i < this->size.y - 2; i++) {
			Console::SetCursorLocation(position.x, position.y + i + 1);
			cout << visuals;

			Console::SetCursorLocation(position.x + size.x - 1, position.y + i + 1);
			cout << visuals;
		}

		visuals = CHAR_192;

		Console::SetCursorLocation(position.x, position.y + size.y - 1);
		cout << visuals;

		visuals = CHAR_196;

		for (int i = 0; i < this->size.x - 2; i++) {
			Console::SetCursorLocation(position.x + i + 1, position.y + size.y - 1);
			cout << visuals;
		}

		visuals = CHAR_217;

		Console::SetCursorLocation(position.x + size.x - 1, position.y + size.y - 1);
		cout << visuals;
	}
}