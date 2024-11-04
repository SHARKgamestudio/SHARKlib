#pragma once

class Array {
protected:
	void** data;
	int capacity;

	void Expand();
	void Shrink();

	[[noreturn]] void IsIndexInBound(int index);

public:

	int length;

	Array(int size);
	~Array();

	void Add(void* element);
	void Insert(void* element, int index);
	void Remove(void* element);
	void RemoveAtIndex(int index);
	void* Get(int index);
	void Set(void* element, int index);
	void Free();

	void* operator[](int index);
	void operator+=(void* element);
};