#include "GraphicComponent.h"

namespace Graphics {
	GraphicComponent::GraphicComponent(int x, int y, int width, int height, int fg_color, int bg_color) {
		this->position = Vector2(x, y);
		this->size = Vector2(width, height);
		
		this->fg_color = fg_color;
		this->bg_color = bg_color;
	}

	GraphicComponent::GraphicComponent(Vector2 position, Vector2 size, int fg_color, int bg_color) {
		this->position = position;
		this->size = size;

		this->fg_color = fg_color;
		this->bg_color = bg_color;
	}
	void GraphicComponent::Draw() {
	}
	void GraphicComponent::Highlight() {
	}
}