#pragma once

#pragma region Local Dependencies

#include "Menu.h"

#pragma endregion

namespace Graphics {
	class VerticalMenu : Menu {
	public:
		void AddElement(GraphicComponent* component);
		void Update() override;
	};
}