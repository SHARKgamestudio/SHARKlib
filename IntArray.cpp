#include "IntArray.h"
#include <iostream>

IntArray::IntArray() {
	this->size = 1;
	this->length = 0;
	this->array = {};

	this->array = (int*)malloc(size * sizeof(int));
}

IntArray::IntArray(int size) {
	this->size = size;
	this->length = 0;
	this->array = {};

	this->array = (int*)malloc(size * sizeof(int));
}

void IntArray::Add(int value) {
	if (this->length >= this->size) {
		int* reallocated = (int*)realloc(this->array, (this->size * 2) * sizeof(int));

		if (reallocated == nullptr)
			return;

		this->array = reallocated;
		size = size * 2;
	}
	if (this->array != nullptr) this->array[this->length] = value;

	length++;
}

void IntArray::Insert(int value, int index) {
	if (this->length >= this->size) {
		int* reallocated = (int*)realloc(this->array, (this->size * 2) * sizeof(int));
		
		if (reallocated == nullptr)
			return;

		this->array = reallocated;
		size = size * 2;
	}
	memcpy(this->array + index + 1, this->array + index, (this->size - index) * sizeof(int));
	this->array[index] = value;
	this->length++;
}

void IntArray::Remove(int index) {
	memcpy(this->array + index, this->array + index + 1, (this->size - index) * sizeof(int));
	this->size--;
	this->length--;
}

int IntArray::Get(int index) {
	if (index > this->length) return NULL;
	return this->array[index];
}

void IntArray::Set(int value, int index) {
	if (index > this->length) exit(1);
	this->array[index] = value;
}

void IntArray::Display() {
	for (int i = 0; i < this->length; i++) {
		std::cout << this->array[i] << ", ";
	}
	std::cout << std::endl;
}

void IntArray::Free() {
	free(this->array);
	this->length = 0;
	this->size = 0;
}