#include "Menu.h"

#pragma region External Dependencies

#include <iostream>
#include <conio.h>

#pragma endregion

#pragma region Local Dependencies

#include "Debug.h"

#pragma endregion

namespace Graphics {
	MenuElement::MenuElement(GraphicComponent* component, int x, int y) {
		this->component = component;
		this->x = x;
		this->y = y;
	}

	Menu::Menu() {
		this->refresh = true;

		this->key_right = 'd';
		this->key_left = 'q';
		this->key_up = 'z';
		this->key_down = 's';
		this->key_confirm = 'e';

		this->elements = nullptr;
		this->length = 0;
		this->selected = Vector2(0, 0);

		this->min_x = 0;
		this->min_y = 0;
		this->max_x = 0;
		this->max_y = 0;
	}
	Menu::Menu(char key_right, char key_left, char key_up, char key_down, char key_confirm) {
		this->refresh = true;
		
		this->key_right = key_right;
		this->key_left = key_left;
		this->key_up = key_up;
		this->key_down = key_down;
		this->key_confirm = key_confirm;

		this->elements = nullptr;
		this->length = 0;
		this->selected = Vector2(0, 0);

		this->min_x = 0;
		this->min_y = 0;
		this->max_x = 0;
		this->max_y = 0;
	}

	void Menu::UpdateBounds() {
		int min_x = 0;
		for (int i = 0; i < length; i++) {
			if (elements[i].x < min_x) { min_x = elements[i].x; }
		}
		this->min_x = min_x;

		int max_x = 0;
		for (int i = 0; i < length; i++) {
			if (elements[i].x > max_x) { max_x = elements[i].x; }
		}
		this->max_x = max_x;

		int min_y = 0;
		for (int i = 0; i < length; i++) {
			if (elements[i].y < min_y) { min_y = elements[i].y; }
		}
		this->min_y = min_y;

		int max_y = 0;
		for (int i = 0; i < length; i++) {
			if (elements[i].y > max_y) { max_y = elements[i].y; }
		}
		this->max_y = max_y;
	}

	void Menu::AddElement(GraphicComponent* component, int x, int y) {
		MenuElement element(component, x, y);

		length++;

		if (elements == nullptr) {
			elements = (MenuElement*)malloc(sizeof(MenuElement));
		}
		else {
			MenuElement* reallocated = (MenuElement*)realloc(elements, sizeof(MenuElement) * length);

			Debug::Assert(reallocated != nullptr, "Memmory allocation failed");

			elements = reallocated;
		}

		Debug::Assert(elements != nullptr, "Memmory allocation failed");

		elements[length - 1] = element;

		this->UpdateBounds();

	}
	void Menu::Update() {

		if (_kbhit()) {
			char input = _getch();

			if (input == key_right && selected.x < max_x) selected.x++;
			if (input == key_left && selected.x > min_x) selected.x--;
			if (input == key_up && selected.y > min_y) selected.y--;
			if (input == key_down && selected.y < max_y) selected.y++;
			if (input == key_confirm) exit(1);

			refresh = true;
		}

		if (refresh == true) {
			for (int i = 0; i < length; i++) {
				if (elements[i].x == selected.x && elements[i].y == selected.y) {
					elements[i].component->Highlight();
				}
				elements[i].component->Draw();
			}
			refresh = false;
		}

	}

}