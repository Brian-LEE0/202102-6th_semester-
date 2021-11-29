#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

SPACE* CreateSpace(int size) {
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
	if (space->size <= space->count) {
		return false;
	}
	element* newData = (element*)malloc(sizeof(element));
	if (!newData) return false;
	*newData = data;
	space->main_memory[space->count++].dataPtr = (void*)newData;
}

bool DestroySpace(SPACE* space) {
	if (!space) return false;
	for (int i = 0; i < space->size; i++) {
		if (space->main_memory[i].dataPtr) {
			free(space->main_memory[i].dataPtr);
		}
	}
}

bool _BinarySearchAlgorithm(SPACE* space, int begin, int end, element target) {
	if (begin > end) return false;
	int mid = (begin + end) / 2;
	if (!(*space->compare)(space->main_memory[mid].dataPtr, &target)) {
		return true;
	}
	if ((*space->compare)(space->main_memory[mid].dataPtr, &target) > 0) {
		_BinarySearchAlgorithm(space, begin, mid - 1, target);
	}
	else {
		_BinarySearchAlgorithm(space, mid + 1, end, target);
	}
}

bool Search(SPACE* space, element target) {
	if (!space) return false;
	if (isEmpty(space)) return false;
	_BinarySearchAlgorithm(space, 0, space->count-1, target);
}


int compare(void* argu1, void* argu2) {
	return (*(element*)argu1) - (*(element*)argu2);
}