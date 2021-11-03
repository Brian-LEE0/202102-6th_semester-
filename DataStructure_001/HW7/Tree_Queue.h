#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef void* Element;

typedef struct QueueNode{
	Element* data;
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



void EnQueue(Queue* pQueue, Element data) {
	QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
		return;

	pNewNode->data = data;
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

Element DeQueue(Queue* pQueue) {

	QueueNode* temp = NULL;
	Element* DQresult = NULL;
	if (pQueue->count == 0) {
		return NULL;
	}
	DQresult = pQueue->front->data;
	temp = pQueue->front;

	if (pQueue->count == 1) {
		pQueue->front = pQueue->rear = NULL;
	}
	else {
		pQueue->front = pQueue->front->next;
	}
	free(temp);
	pQueue->count--;
	return DQresult;

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

void DestroyQueue(Queue* pQueue) {
	QueueNode* temp;
	while (pQueue->count > 0) {
		temp = pQueue->front;
		pQueue->front = pQueue->front->next;
		free(temp->data);
		free(temp);
		pQueue->count--;
	}
	free(pQueue);
	return;
}
