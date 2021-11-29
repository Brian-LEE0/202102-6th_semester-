#include "Structure.h"


SPACE* B_CreateSpace(int size, int (*compare)(void* argu1, void* argu2)) {
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

bool B_isFull(SPACE* space) {
	if (!space->main_memory) {
		return true;
	}
	if (space->count == space->size) {
		return true;
	}
	return false;
}

bool B_isEmpty(SPACE* space) {
	if (!space->main_memory) return true;
	if (space->count == 0) return true;
	return false;
}

bool B_SaveData(SPACE* space, element data) {
	if (!space) {
		return false;
	}
	if (B_isFull(space)) {
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

bool B_DestroySpace(SPACE* space) {
	if (!space) return false;
	for (int i = 0; i < space->count; i++) {
		if (space->main_memory[i].dataPtr) {
			free(space->main_memory[i].dataPtr);
		}
	}
	free(space->main_memory);
	free(space);
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

bool B_Search(SPACE* space, element target) {
	if (!space) return false;
	if (B_isEmpty(space)) return false;
	_BinarySearchAlgorithm(space, 0, space->count-1, target);
}
