#pragma once

#pragma region Local Dependencies

#include "Vector2.h"
#include "GraphicComponent.h"

#pragma endregion

namespace Graphics {
	struct MenuElement {
		GraphicComponent* component;
		int x, y;

		MenuElement(GraphicComponent* component, int x, int y);
	};
	
	class Menu {
	private:
		Vector2 selected;
		int min_x, min_y, max_x, max_y;

		MenuElement* elements;
		int length;

		bool refresh;
		void UpdateBounds();
	public:
		char key_right, key_left, key_up, key_down, key_confirm;

		Menu();
		Menu(char key_right, char key_left, char key_up, char key_down, char key_confirm);

		void AddElement(GraphicComponent* component, int x, int y);
		void Update();
	};
}