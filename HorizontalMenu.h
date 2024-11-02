#pragma once

#pragma region Local Dependencies

#include "Menu.h"

#pragma endregion

namespace Graphics {
	class HorizontalMenu : Menu {
	public:
		void AddElement(GraphicComponent* component);
		void Update() override;
	};
}