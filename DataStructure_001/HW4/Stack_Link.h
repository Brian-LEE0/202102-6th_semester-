#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode;

typedef struct {
	int count;
	StackNode* top;	
}Stack;

Stack* CreateStack(int size) { //size is not used
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL) {
		return NULL;
	}
	pStack->count = 0;
	pStack->top = NULL;

	return pStack;
}

void Push(Stack* pStack, int item) {
	StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode));
	if (pNewNode == NULL){
		return;
	}

	pNewNode->data = item;
	pNewNode->next = pStack->top;
	pStack->top = pNewNode;
	pStack->count++;
}

int Pop(Stack* pStack) {
	if (pStack->top == NULL) {
		return EOF;
	}
	int item = pStack->top->data;
	StackNode* pOldTop = pStack->top;
	pStack->top = pOldTop->next;
	free(pOldTop);
	pStack->count--;
	return item;
}

void DestroyStack(Stack* pStack) {
	StackNode* pOldTop;
	for (int i = 0; i < pStack->count; i++) {
		pOldTop = pStack->top;
		pStack->top = pOldTop->next;
		free(pOldTop);
	}
	free(pStack);
}

int Top(Stack* pStack) {
	if (pStack->top == NULL) {
		return EOF;
	}
	int item = pStack->top->data;
	return item;
}

bool IsFullStack(Stack* pStack) {
	return false; // cuz we cannot fix the size of Stack in linked stack
}

bool IsEmptyStack(Stack* pStack) {
	if (pStack->top == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int CountStackItem(Stack* pStack) {
	return pStack->count;
}
