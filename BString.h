#pragma once

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Color.h"

#pragma endregion

using namespace std;

class String {
private:
	char* content;

	char fg_color[4] = "037";
	char bg_color[4] = "030";

public:
	int length;

	String();
	String(const char content);
	String(const char* content);

	static String Concatenate(const char* chars1, const char* chars2);
	static String Concatenate(String* string1, const char* chars2);
	static String Concatenate(const char* chars1, String* string2);
	static String Concatenate(String* string1, String* string2);

	void operator=(const char* content);
	void operator=(const char content);

	void operator+=(const char* content);
	void operator+=(String content);

	String operator+(const char* content);
	String operator+(String content);

	void SetFGColor(Color color);
	void SetBGColor(Color color);

	friend ostream& operator<<(ostream& os, const String& str);
};