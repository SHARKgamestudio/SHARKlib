#pragma once

#pragma region Local Dependencies

#include "Vector2.h"

#pragma endregion

#pragma region External Dependencies

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>

#pragma endregion

namespace Graphics {
	namespace Console {
		enum WindowMode {
			Normal = SW_NORMAL,
			Minimized = SW_MINIMIZE,
			Maximized = SW_MAXIMIZE,
			Fullscreen = 9999,
			Hidden = SW_HIDE,
			Shown = SW_SHOW
		};

		void SetWindowMode(WindowMode mode);

		void SetFont(int size);
		void SetFont(Vector2 size);
		void SetFont(int width, int height);

		void SetCursorVisibility(bool visible);

		void SetCursorLocation(int x, int y);
		void SetCursorLocation(Vector2 location);

		Vector2 GetSize();
	}
}