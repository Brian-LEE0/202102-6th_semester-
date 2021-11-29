#pragma once
#define_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int compare(void* argu1, void* argu2);

typedef int element;

typedef struct space {
	int (*compare)(void* argu1, void* argu2);
	int count;
	int size;
	struct memory* main_memory;
}SPACE;

typedef struct memory {
	void* dataPtr;
}MEMORY;

int _HashingFunction(SPACE* space, element key, int memory_size_digit) {//
	int hashed_result = 0;
	key = (int)pow(key, 2); // key square
	for (int i = 0; i < memory_size_digit; i++) {
		hashed_result += (key % 10) * ((int)pow(10, i));
		key /= 10;
	}

	if (hashed_result == 0) {
		hashed_result = 13;
	}
	if (hashed_result >= space->size) {
		hashed_result = _HashingFunction(space, hashed_result, memory_size_digit);
	}
	return hashed_result;

}

int _num_of_digit(int n) {
	if (n == 0) {
		return 0;
	}
	while (n != 0) {
		return 1 + _num_of_digit(n / 10);
	}
	return 0;
}

SPACE* CreateSpace(int size, int (*compare)(void* argu1, void* argu2)) {
	SPACE* pNewSpace = (SPACE*)malloc(sizeof(SPACE));
	if (!pNewSpace) return NULL;
	pNewSpace->main_memory = (MEMORY*)malloc(sizeof(MEMORY) * size);
	if (!pNewSpace->main_memory) return NULL;
	for (int i = 0; i < size; i++) {
		pNewSpace->main_memory[i].dataPtr = NULL;
	}
	pNewSpace->count = 0;
	pNewSpace->size = size;
	pNewSpace->compare = compare;
	return pNewSpace;
}

bool isFull(SPACE* space) {
	if (!space->main_memory) {
		return true;
	}
	if (space->count == space->size) {
		return true;
	}
	return false;
}

bool isEmpty(SPACE* space) {
	if (!space->main_memory) return true;
	if (space->count == 0) return true;
	return false;
}

bool SaveData(SPACE* space, element data) {
	if (!space) {
		return false;
	}
	if (isFull(space)) {
		return false;
	}
	int address = _HashingFunction(space, data, _num_of_digit(space->size - 1));

	while (1) {
		if (space->main_memory[address].dataPtr != NULL) {
			address = _HashingFunction(space, address, _num_of_digit(space->size - 1));
		}
		else {
			break;
		}
	}

	element* newData = (element*)malloc(sizeof(element));
	if (!newData) return false;
	*newData = data;
	space->main_memory[address].dataPtr = (void*)newData;
	space->count++;
	return true;
}

bool DestroySpace(SPACE* space) {
	if (!space) return false;
	for (int i = 0; i < space->size; i++) {
		if (space->main_memory[i].dataPtr) {
			free(space->main_memory[i].dataPtr);
		}
	}
}


bool Search(SPACE* space, element target) {
	if (!space)	return false;
	if (isEmpty(space)) return false;
	int address = _HashingFunction(space, target, _num_of_digit(space->size - 1));
	while (1) {
		if (space->main_memory[address].dataPtr == NULL) {

			return false;
		}
		if ((*space->compare)(space->main_memory[address].dataPtr, &target) == 0) {
			return true;
		}else {
			address = _HashingFunction(space, address, _num_of_digit(space->size - 1));
		}
	}
}
