#include "Button.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Ascii.h"
#include "RichText.h"
#include "Console.h"

#pragma endregion

using namespace std;
using namespace Graphics;

Button::Button(const char* label, int x, int y, int width, int height, int normal_color, int highlight_color) : Frame(x, y, width, height, normal_color) {
	this->label = RichText(label);
	this->normal_color = normal_color;
	this->highlight_color = highlight_color;

	this->current_color = normal_color;
}
Button::Button(const char* label, Vector2 position, Vector2 size, int normal_color, int highlight_color) : Frame(position, size, normal_color) {
	this->label = RichText(label);
	this->normal_color = normal_color;
	this->highlight_color = highlight_color;

	this->current_color = normal_color;
}

void Button::Draw() {
	label.SetFGColor(current_color);
	fg_color = current_color;
	Frame::Draw();

	Console::SetCursorLocation(position.x, position.y + int(size.y / 2));

	int spaces = int(size.x / 2) - int(label.length / 2);
	for (int i = 0; i < spaces; i++) {
		cout << ' ';
	}
	cout << label;

	current_color = normal_color;
}

void Graphics::Button::Highlight() {
	current_color = highlight_color;
}