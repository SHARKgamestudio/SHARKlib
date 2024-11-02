#include "VerticalMenu.h"

namespace Graphics {
	void VerticalMenu::AddElement(GraphicComponent* component) {
		Menu::AddElement(component, 0, this->length);
	}

	void VerticalMenu::Update() {
		Menu::Update();
	}
}