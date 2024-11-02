#pragma once

#define CL_FOREGROUND "\033[38;5;"
#define CL_BACKGROUND "\033[48;5;"
#define CL_RESET "\033[0m"

namespace Graphics {
	enum Color {
        Black = 0,
        White = 7,

        Red = 1,
        Green = 2,
        Blue = 4,

        Yellow = 3,
        Magenta = 5,
        Cyan = 6,

        Bright_Black = 8,
        Bright_White = 15,

        Bright_Red = 9,
        Bright_Green = 10,
        Bright_Blue = 12,

        Bright_Yellow = 11,
        Bright_Magenta = 13,
        Bright_Cyan = 14,
	};

	int RGBToAnsi(int r, int g, int b);
}