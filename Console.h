#pragma once

class Console {
public:
	static void SetFont(int size = 12);
	static void SetCursorVisibility(bool visible);
	static void SetCursorLocation(int x, int y);
};