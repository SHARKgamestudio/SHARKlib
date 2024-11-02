#pragma once

class IntArray {
private:
	/// <summary>
	/// The data-container of the array.
	/// </summary>
	int* array;
	/// <summary>
	/// The size of the array in memory.
	/// </summary>
	int size;
public:
	/// <summary>
	/// The number of elements in the array.
	/// </summary>
	int length;

	/// <summary>
	/// Create a new DynamicArray with a size of 1.
	/// </summary>
	IntArray();
	/// <summary>
	/// Create a new DynamicArray with a default size.
	/// </summary>
	/// <param name="size">: The size of the array in Bytes.</param>
	IntArray(int size);

	void Add(int value);

	void Insert(int value, int index);

	void Remove(int index);

	int Get(int index);

	void Set(int value, int index);

	void Display();

	void Free();
};