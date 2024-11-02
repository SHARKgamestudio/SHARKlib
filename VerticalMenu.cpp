#include "VerticalMenu.h"

namespace Graphics {
	void Graphics::VerticalMenu::AddElement(GraphicComponent* component) {
		Menu::AddElement(component, 0, this->length);
	}

	void Graphics::VerticalMenu::Update() {
		Menu::Update();
	}
}