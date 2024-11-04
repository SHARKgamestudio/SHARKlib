#include "Memory.h";

#pragma region External Dependencies

#include <iostream>

#pragma endregion

namespace Memory {

	#pragma region Swap

	#pragma region Whole Numbers

	void Swap(int* a, int* b) {
		int temporary = *a;
		*a = *b;
		*b = temporary;
	}

	void Swap(short* a, short* b) {
		short temporary = *a;
		*a = *b;
		*b = temporary;
	}

	void Swap(long* a, long* b) {
		long temporary = *a;
		*a = *b;
		*b = temporary;
	}

	#pragma endregion

	#pragma region Decimal Numbers

	void Swap(float* a, float* b) {
		float temporary = *a;
		*a = *b;
		*b = temporary;
	}

	void Swap(double* a, double* b) {
		double temporary = *a;
		*a = *b;
		*b = temporary;
	}

	#pragma endregion

	#pragma region Others

	void Swap(bool* a, bool* b) {
		bool temporary = *a;
		*a = *b;
		*b = temporary;
	}

	void Swap(char* a, char* b) {
		char temporary = *a;
		*a = *b;
		*b = temporary;
	}

	#pragma endregion

	#pragma endregion

	void Swap(void* a, void* b) {
		void* temporary = a;
		a = b;
		b = temporary;
	}

}