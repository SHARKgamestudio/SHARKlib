#include "Button.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Ascii.h"
#include "BString.h"
#include "Console.h"

#pragma endregion

using namespace std;

Button::Button(const char* label, Vector2 size) : Frame(size) {
	this->label = String(label);
}
Button::Button(const char* label, int width, int height, int x, int y) : Frame(width, height, x, y) {
	this->label = String(label);
}
Button::Button(const char* label, Vector2 size, Vector2 position) : Frame(size, position) {
	this->label = String(label);
}

void Button::Draw() {
	Frame::Draw();

	Console::SetCursorLocation(position.x, position.y + int(size.y / 2));

	int spaces = int(size.x / 2) - int(label.length / 2);
	for (int i = 0; i < spaces; i++) {
		cout << ' ';
	}
	cout << label;
}