#pragma once

class Char {
public:
	static char* CharArrayFromInt(int value);
	static int GetLength(const char* chars);
	static char* Concatenate(const char* chars0, const char* chars1);
};