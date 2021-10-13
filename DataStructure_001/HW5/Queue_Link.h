#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[100];

typedef struct QueueNode{
	char name[100];
	struct QueueNode* next;
}QueueNode;

typedef struct {
	int count;
	QueueNode* front, * rear;
}Queue;

Queue* CreateQueue(int size) {
	Queue* pNewQueue = (Queue*)malloc(sizeof(Queue));
	if (pNewQueue == NULL)
		return NULL;

	pNewQueue->count = 0;
	pNewQueue->front = pNewQueue->rear = NULL;

	return pNewQueue;
}



void EnQueue(Queue* pQueue, char* name) {
	QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
		return;

	strcpy(pNewNode->name, name);
	pNewNode->next = NULL;

	if (pQueue->count == 0) {
		pQueue->front = pQueue->rear = pNewNode;
	}
	else {
		pQueue->rear->next = pNewNode;
		pQueue->rear = pNewNode;
	}

	pQueue->count++;
}

char* DeQueue(Queue* pQueue,char* input_name) {
	
	QueueNode* temp = NULL;

	if (pQueue->count == 0) {
		return NULL;
	}

	strcpy(name, pQueue->front->name);
	temp = pQueue->front;

	if (pQueue->count == 1) {
		pQueue->front = pQueue->rear = NULL;
	}
	else {
		pQueue->front = pQueue->front->next;
	}
	free(temp);
	pQueue->count--;
	return name;

}

int isFull(Queue* pQueue) {
	return 0;
}

int isEmpty(Queue* pQueue) {
	if (pQueue->count == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void DistroyQueue(Queue* pQueue) {
	QueueNode* temp;
	while (pQueue->count > 0) {
		temp = pQueue->front;
		pQueue->front = pQueue->front->next;
		free(temp);//Queue list 반환
		pQueue->count--;
	}
	free(pQueue);//Queue 반환
	return;
}

void printallQueue(Queue* pQueue) {
	QueueNode* temp;
	if (pQueue->count == 0) {
		return;
	}
	printf("(");
	temp = pQueue->front;
	for (int i = 0; i < pQueue->count; i++) {
		printf("%s", temp->name);
		temp = temp->next;
		printf("%d", i + 1);
		if (i != (pQueue->count - 1)) {
			printf(", ");
		}
	}
	printf(")\n");
}