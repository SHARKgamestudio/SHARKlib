#include "Vector2.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

Vector2::Vector2() {
	this->x = 0;
	this->y = 0;
	this->magnitude = 0;
}

Vector2::Vector2(int x, int y) {
	this->x = x;
	this->y = y;
	this->magnitude = (int)sqrt((x*x)+(y*y));
}