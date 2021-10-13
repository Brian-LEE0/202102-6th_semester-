#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct List {
	Element data;
}ListNode;

typedef struct {
	int count;
	int pos;
	int size;
	ListNode* list;
}List;

List* createList(int size) {
	List* pNewList = (List*)malloc(sizeof(List));
	if (pNewList == NULL) {
		return NULL;
	}
	
	pNewList->list = (ListNode*)malloc(sizeof(ListNode) * size);
	pNewList->count = pNewList->pos = 0;
	pNewList->size = size;

	return pNewList;
}

void _insertList(List* pList, Element data) {


	if (pList == NULL) {
		return;
	}
	
	if (pList->count == 0) {
		pList->list[0].data = data;
		pList->count++;
		return;
	}

	for (int i = 0; i < pList->count; i++) {
		if (data < pList->list[i].data) {
			for (int j = pList->count; j > i; j--) {
				pList->list[j] = pList->list[j - 1];
			}
			pList->list[i].data = data;
			pList->count++;
			return;
		}
	}
	
	pList->list[pList->count].data = data;
	pList->count++;
	return;
}

int _searchList(List* pList, Element data) {
	for (int i = 0; i < pList->count; i++) {
		if (pList->list[i].data == data)
			return i;
		else if (pList->list[i].data > data)
			break;
	}
	return -1;
}

int addNodeList(List* pList, Element data) {
	int found = _searchList(pList, data);

	if (found < 0) {
		if (pList->size == pList->count) {
			return -1;
		}
		_insertList(pList, data);
		return true;
	}
	return false;
		
}


bool removeList(List* pList, Element data) {

	int found = _searchList(pList, data);

	if (found >= 0) {
		for (int i = found; i < pList->count-1; i++) {
			pList->list[i] = pList->list[i + 1];
		}
		pList->count--;
		return true;
	}
	return false;
}

int traverseList(List* pList, int fromWhere, Element* pDataOut) {
	if (fromWhere == 0)
		pList->pos = 0;

	if (pList->pos < pList->count) {
		*pDataOut = pList->list[pList->pos++].data;
		return true;
	}
	else {
		*pDataOut = 0;
		pList->pos = 0;
		return false;
	}
}

void destroyList(List* pList) {

	free(pList->list);
	free(pList);
}