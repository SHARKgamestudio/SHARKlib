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

		char fg_color[4] = "037";
		char bg_color[4] = "030";

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

		void SetFGColor(Color color);
		void SetBGColor(Color color);

		friend ostream& operator<<(ostream& os, const RichText& str);
	};
}