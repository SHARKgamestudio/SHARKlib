#pragma once

class Debug {
public:
	[[noreturn]] static void Assert(bool condition, const char* message, bool quit = true);
};