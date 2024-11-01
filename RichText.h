#pragma once

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Color.h"

#pragma endregion

using namespace std;

namespace Graphics {
	class RichText {
	private:
		char* content;

		char fg_color[4] = "007";
		char bg_color[4] = "000";

	public:
		int length;

		RichText();
		RichText(const char content);
		RichText(const char* content);

		static RichText Concatenate(const char* chars1, const char* chars2);
		static RichText Concatenate(RichText* string1, const char* chars2);
		static RichText Concatenate(const char* chars1, RichText* string2);
		static RichText Concatenate(RichText* string1, RichText* string2);

		void operator=(const char* content);
		void operator=(const char content);

		void operator+=(const char* content);
		void operator+=(RichText content);

		RichText operator+(const char* content);
		RichText operator+(RichText content);

		void SetFGColor(int color);
		void SetFGColor(int r, int g, int b);

		void SetBGColor(int color);
		void SetBGColor(int r, int g, int b);

		friend ostream& operator<<(ostream& os, const RichText& str);

		static void InitConsoleToUTF8();
	};
}