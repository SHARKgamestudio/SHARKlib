#include "Char.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Debug.h"

#pragma endregion

char* Char::CharArrayFromInt(int value) {
	char* chars = (char*)malloc(16 * sizeof(char));

	Debug::Assert(chars != nullptr, "Memmory Allocation Failed");

#ifdef _MSC_VER
	sprintf_s(chars, 16, "%d", value);
#else
	sprintf(buffer, "%d", num);
#endif

	return chars;
}

int Char::GetLength(const char* chars) {
	int index = 0;
	while (chars[index] != '\0')
		index++;

	return index;
}

char* Char::Concatenate(const char* chars0, const char* chars1) {
	int length0 = GetLength(chars0);
	int length1 = GetLength(chars1);

	char* concatenated = new char[(length0 + length1) + 1] {};

	Debug::Assert(concatenated != nullptr, "Memmory Allocation Failed");

	for (int i = 0; i < length0; i++) {
		concatenated[i] = chars0[i];
	}


	for (int j = 0; j < length1; j++) {
		concatenated[length0 + j] = chars1[j];
	}


	concatenated[length0 + length1] = '\0';

	return concatenated;
}