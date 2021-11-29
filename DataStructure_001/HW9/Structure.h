#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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