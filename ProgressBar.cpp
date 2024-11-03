#include "ProgressBar.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Console.h"
#include "RichText.h"
#include "Ascii.h"

#pragma endregion

using namespace std;

namespace Graphics {
	ProgressBar::ProgressBar(int x, int y, int width, int height, int fg_color, int bg_color) : GraphicComponent(x, y, width, height, fg_color, bg_color) {
		this->value = 0;
	}
	ProgressBar::ProgressBar(Vector2 position, Vector2 size, int fg_color, int bg_color) : GraphicComponent(position, size, fg_color, bg_color) {
		this->value = 0;
	}
	
	void ProgressBar::Draw() {
		int percent = int((float)value * ((float)size.x / 100.0f));

		Console::SetCursorLocation(position);

		RichText visuals(CHAR_219);

		visuals.SetFGColor(fg_color);

		cout << percent << "%" << (percent < 10 ? "  " : " ");

		cout << CHAR_179;

		for (int i = 0; i < percent; i++) {
			cout << visuals;
		}
		for (int i = 0; i < size.x - percent; i++) {
			cout << " ";
		}

		cout << CHAR_179;
	}
	void ProgressBar::UpdateValue(int value) {
		this->value = value;

		Draw();
	}
}