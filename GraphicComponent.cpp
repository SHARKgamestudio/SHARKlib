#include "GraphicComponent.h"

namespace Graphics {
	GraphicComponent::GraphicComponent(int x, int y, Color color) {
		this->position = Vector2(x, y);
		this->color = color;
	}

	GraphicComponent::GraphicComponent(Vector2 position, Color color) {
		this->position = position;
		this->color = color;
	}
}