#include "HorizontalMenu.h"

namespace Graphics {
	void HorizontalMenu::AddElement(GraphicComponent* component) {
		Menu::AddElement(component, this->length, 0);
	}

	void HorizontalMenu::Update() {
		Menu::Update();
	}
}