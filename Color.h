#pragma once

#define CL_PREFIX "\033[3;"
#define CL_SUFFIX "\033[0m"

enum Color {
	Black = 30,
	White = 37,
	Red = 31,
	Green = 32,
	Blue = 34,
	Yellow = 33,
	Magenta = 35,
	Cyan = 36,

	BrightBlack = 90,
	BrightWhite = 97,
	BrightRed = 91,
	BrightGreen = 92,
	BrightYellow = 93,
	BrightBlue = 94,
	BrightMagenta = 95,
	BrightCyan = 96,
};