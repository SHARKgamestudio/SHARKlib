#include "RichText.h"

#pragma region External Dependencies

#include <iostream>
#include <locale>

#pragma endregion

#pragma region Local Dependencies

#include "Color.h"
#include "Debug.h"
#include "Char.h"

#pragma endregion

namespace Graphics {
	RichText::RichText() {
		//RichText::InitConsoleToUTF8();

		this->content = nullptr; this->length = 0;
	}
	RichText::RichText(const char content) {
		//RichText::InitConsoleToUTF8();
		
		this->length = 1;
		this->content = new char[this->length + 1];

		Debug::Assert(this->content != nullptr, "Error Allocating Memmory !");

		this->content[0] = content;

		this->content[this->length] = '\0';
	}
	RichText::RichText(const char* content) {
		//RichText::InitConsoleToUTF8();

		this->length = Char::GetLength(content);
		this->content = new char[this->length + 1];

		Debug::Assert(this->content != nullptr, "Error Allocating Memmory !");

		for (int i = 0; i < this->length; i++)
			this->content[i] = content[i];

		this->content[this->length] = '\0';
	}

	RichText RichText::Concatenate(const char* chars1, const char* chars2) {
		int length0 = Char::GetLength(chars1);
		int length1 = Char::GetLength(chars2);

		RichText result;
		result.length = length0 + length1;
		result.content = Char::Concatenate(chars1, chars2);

		return result;
	}
	RichText RichText::Concatenate(RichText* string1, const char* chars2) {
		RichText converted(chars2);
		return RichText::Concatenate(string1, &converted);
	}
	RichText RichText::Concatenate(const char* chars1, RichText* string2) {
		RichText converted(chars1);
		return RichText::Concatenate(string2, &converted);
	}
	RichText RichText::Concatenate(RichText* string1, RichText* string2) {
		RichText result;
		result.length = string1->length + string2->length;
		result.content = Char::Concatenate(string1->content, string2->content);

		Debug::Assert(result.content != nullptr, "Error Allocating Memmory !");

		return result;
	}

	void RichText::operator=(const char* content) {
		this->content = (char*)content;
	}

	void RichText::operator=(const char content) {
		this->content = new char[2];
		this->content[0] = content;
		this->content[1] = '\0';
	}

	void RichText::operator+=(const char* content) {
		this->content = Char::Concatenate(this->content, content);
	}
	void RichText::operator+=(RichText content) {
		this->content = Char::Concatenate(this->content, content.content);
	}

	RichText RichText::operator+(const char* content) {
		return RichText::Concatenate(this, content);
	}
	RichText RichText::operator+(RichText content) {
		return RichText::Concatenate(this, &content);
	}

	void RichText::SetFGColor(int color) {
		sprintf_s(this->fg_color, 4, "%d", color);
		if (color < 100) {
			this->fg_color[2] = this->fg_color[1];
			this->fg_color[1] = this->fg_color[0];
			this->fg_color[0] = '0';
		}

		this->fg_color[3] = '\0';
	}
	void RichText::SetFGColor(int r, int g, int b){
		int color = RGBToAnsi(r, g, b);

		sprintf_s(this->fg_color, 4, "%d", color);
		if (color < 100) {
			this->fg_color[2] = this->fg_color[1];
			this->fg_color[1] = this->fg_color[0];
			this->fg_color[0] = '0';
		}

		this->fg_color[3] = '\0';
	}
	void RichText::SetBGColor(int color) {
		sprintf_s(bg_color, 4, "%d", color);
		if (color < 100) {
			this->bg_color[2] = this->bg_color[1];
			this->bg_color[1] = this->bg_color[0];
			this->bg_color[0] = '0';
		}

		this->bg_color[3] = '\0';
	}
	void RichText::SetBGColor(int r, int g, int b) {
		int color = RGBToAnsi(r, g, b);
		sprintf_s(bg_color, 4, "%d", color);
		if (color < 100) {
			this->bg_color[2] = this->bg_color[1];
			this->bg_color[1] = this->bg_color[0];
			this->bg_color[0] = '0';
		}

		this->bg_color[3] = '\0';
	}

	void RichText::InitConsoleToUTF8() {
		setlocale(LC_ALL, "en_US.UTF-8");
	}

	ostream& operator<<(ostream& os, const RichText& str) {
		os << CL_FOREGROUND << str.fg_color << "m" CL_BACKGROUND << str.bg_color << "m" << str.content << CL_RESET;
		return os;
	}
}