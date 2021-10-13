#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[100];

typedef struct {
	char name[100];
}Name;

typedef struct {
	Name* name;
	int front, rear, size;
}Queue;

Queue* CreateQueue(int size) {
	Queue* pNewQueue = (Queue*)malloc(sizeof(Queue));
	if (pNewQueue == NULL)
		return NULL;

	pNewQueue->front = pNewQueue->rear = 0;
	pNewQueue->name = (Name*)malloc(sizeof(Name) * size);
	pNewQueue->size = size;
	
	return pNewQueue;
}



void EnQueue(Queue* pQueue, char* name) {
	if ((pQueue->rear + 1) % pQueue->size == pQueue->front) {
		return;
	}

	strcpy(pQueue->name[pQueue->rear % pQueue->size].name, name);
	pQueue->rear++;
}

char* DeQueue(Queue* pQueue, char* input_name) {
	

	if (pQueue->rear == pQueue->front) {
		return NULL;
	}


	strcpy(temp, pQueue->name[pQueue->front % pQueue->size].name);

	pQueue->front++;

	return temp;

}

int isEmpty(Queue* pQueue) {
	if (pQueue->rear == pQueue->front) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(Queue* pQueue) {
	if ((pQueue->rear + 1) % pQueue->size == pQueue->front) {
		return 1;
	}
	else {
		return 0;
	}
}

void DistroyQueue(Queue* pQueue) {
	if (pQueue->name != NULL) {
		free(pQueue->name);//name 반환
	}
	free(pQueue);//Queue 반환
	return;
}

void printallQueue(Queue* pQueue) {

	int j = 0;
	if (pQueue->rear == pQueue->front) {
		return;
	}
	printf("(");
	for (int i = pQueue->front; i < pQueue->rear; i++) {
		printf("%s", pQueue->name[i % pQueue->size].name);
		printf("%d", ++j);
		if (i != (pQueue->rear - 1)) {
			printf(", ");
		}
	}
	printf(")\n");
}