#include "Debug.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

using namespace std;

[[noreturn]] void Debug::Assert(bool condition, const char* message, bool quit) {
	if (condition)
		return;

	cout << "Assertion failed ";
	cout << message << endl;

	if (quit)
		exit(1);
}