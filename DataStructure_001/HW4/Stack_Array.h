#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int* stack;
	int size;
	int top;
}Stack;

Stack* CreateStack(int size) {
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL) {
		return NULL;
	}
	pStack->stack = (int*)malloc(sizeof(int) * size);
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}

	pStack->size = size;
	pStack->top = -1;

	return pStack;
}

void Push(Stack* pStack, int item) {
	if (pStack->top == pStack->size - 1) {
		return;

	}
	pStack->stack[++pStack->top] = item;
}

int Pop(Stack* pStack) {
	if (pStack->top < 0){
		return EOF; //stack is Empty
	}
	
	return pStack->stack[pStack->top--];

}

void DestroyStack(Stack* pStack) {
	if (pStack->size > 0) {
		free(pStack->stack);
	}
	free(pStack);
}

int Top(Stack* pStack) {
	if (pStack->top < 0) {
		return EOF;
	}

	return pStack->stack[pStack->top];
}

bool IsFullStack(Stack* pStack) {
	if (pStack->top == pStack->size - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool IsEmptyStack(Stack* pStack) {
	if (pStack->top == -1) {
		return true;
	}
	else {
		return false;
	}
}

int CountStackItem(Stack* pStack) {
	return pStack->top+1;
}
