#include "Array.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "Memory.h"
#include "Debug.h"

#pragma endregion

Array::Array(int size) {
	this->capacity = size;
	this->length = 0;
	this->data = {};

	this->data = (void**)malloc(size * sizeof(void**));
}

Array::~Array() {
	this->capacity = 0;
	this->length = 0;
	free(this->data);
}

void Array::Expand() {
	if (length >= capacity) {
		capacity *= 2;
		void** reallocated = (void**)realloc(data, capacity * sizeof(void*));
		if (reallocated != nullptr) data = reallocated; else exit(1);
	}
}

void Array::Shrink() {
	capacity = length;
	void** reallocated = (void**)realloc(data, capacity * sizeof(void*));
	if (reallocated != nullptr) data = reallocated; else exit(1);
}

[[noreturn]] void Array::IsIndexInBound(int index) {
	Debug::Assert((index < length && index >= 0), "Index Out Of Bounds.");
}

void Array::Add(void* element) {
	Expand();

	data[length] = element;
	length++;
}

void Array::Insert(void* element, int index) {
	IsIndexInBound(index);

	Expand();

	memcpy(data + index + 1, data + index, (length - index) * sizeof(void*));
	data[index] = element;
	length++;
}

void Array::Remove(void* element) {
	for (int i = 0; i < length; i++) {
		if (data[i] == element) {
			Memory::Swap(&data[i], &data[length - 1]);
			length--;
			Shrink();
		}
	}
}

void Array::RemoveAtIndex(int index) {
	IsIndexInBound(index);

	delete data[index];
	memcpy(data + index, data + index + 1, (length - index) * sizeof(void*));
	length--;
}

void* Array::Get(int index) {
	IsIndexInBound(index);
	return data[index];
}

void Array::Set(void* element, int index) {
	IsIndexInBound(index);
	data[index] = element;
}

void Array::Free() {
	capacity = 0;
	length = 0;
	free(data);
}

void* Array::operator[](int index) {
	IsIndexInBound(index);
	return data[index];
}

void Array::operator+=(void* element) {
	Add(element);
}
