#include "Color.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

using namespace std;

namespace Graphics {
	int RGBToAnsi(int r, int g, int b) {
        r = max(0, min(255, r));
        g = max(0, min(255, g));
        b = max(0, min(255, b));

        // Formula: 16 + 36 * R + 6 * G + B
        int ansiCode = 16 + (36 * (r / 51)) + (6 * (g / 51)) + (b / 51);
        return ansiCode;
	}
}