#pragma once

namespace Memory {

	#pragma region Swap

	#pragma region Whole Numbers

	/// <summary>
	/// Swap two integers in memory.
	/// </summary>
	/// <param name="a">: address of the first int.</param>
	/// <param name="b">: address of the second int.</param>
	void Swap(int* a, int* b);

	/// <summary>
	/// Swap two short in memory.
	/// </summary>
	/// <param name="a">: address of the first short.</param>
	/// <param name="b">: address of the second short.</param>
	void Swap(short* a, short* b);

	/// <summary>
	/// Swap two long in memory.
	/// </summary>
	/// <param name="a">: address of the first long.</param>
	/// <param name="b">: address of the second long.</param>
	void Swap(long* a, long* b);

	#pragma endregion

	#pragma region Decimal Numbers

	/// <summary>
	/// Swap two float in memory.
	/// </summary>
	/// <param name="a">: address of the first float.</param>
	/// <param name="b">: address of the second float.</param>
	void Swap(float* a, float* b);

	/// <summary>
	/// Swap two double in memory.
	/// </summary>
	/// <param name="a">: address of the first double.</param>
	/// <param name="b">: address of the second double.</param>
	void Swap(double* a, double* b);

	#pragma endregion

	#pragma region Others

	/// <summary>
	/// Swap two bool in memory.
	/// </summary>
	/// <param name="a">: address of the first bool.</param>
	/// <param name="b">: address of the second bool.</param>
	void Swap(bool* a, bool* b);

	/// <summary>
	/// Swap two char in memory.
	/// </summary>
	/// <param name="a">: address of the first char.</param>
	/// <param name="b">: address of the second char.</param>
	void Swap(char* a, char* b);

	#pragma endregion

	#pragma endregion

	void Swap(void* a, void* b);
}