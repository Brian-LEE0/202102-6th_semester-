#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

typedef struct tListNode {
	Element data;
	struct tListNode* link;
}ListNode;

typedef struct {
	int count, size;
	ListNode* pos;
	ListNode* head;
}List;

List* createList(int size) {
	List* pNewList = (List*)malloc(sizeof(List));
	if (pNewList == NULL) {
		return NULL;
	}

	pNewList->count = 0;
	pNewList->size = size;
	pNewList->head = pNewList->pos = NULL;

	return pNewList;
}

void _insertList(List* pList, ListNode* pPre, Element data) {
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
	pNewNode->data = data;

	if (pPre == NULL) {
		pNewNode->link = pList->head;
		pList->head = pNewNode;
	}
	else {
		pNewNode->link = pPre->link;
		pPre->link = pNewNode;
	}

	pList->count++;
}

bool _searchList(List* pList, ListNode** ppPre, ListNode** ppLoc, Element data) {
	for (*ppPre = NULL, *ppLoc = pList->head; *ppLoc != NULL; *ppPre = *ppLoc, *ppLoc = (*ppLoc)->link) {
		if ((*ppLoc)->data == data)
			return true;
		else if ((*ppLoc)->data > data)
			break;
	}
	return false;
}

int addNodeList(List* pList, Element data) {
	ListNode* pPre = NULL, * pLoc = NULL;
	
	bool found = _searchList(pList, &pPre, &pLoc, data);

	if (!found) {
		if (pList->size == pList->count) {
			return -1;
		}
		_insertList(pList, pPre, data);
		return true;
	}
	return false;
	
		
	
}

void _deleteList(List* pList, ListNode* pPre, ListNode* pLoc) {
	if (pPre == NULL)
		pList->head = pLoc->link;
	else
		pPre->link = pLoc->link;

	free(pLoc);
	pList->count--;
}

bool removeList(List* pList, Element data) {
	ListNode* pPre = NULL, * pLoc = NULL;
	bool found = _searchList(pList, &pPre, &pLoc, data);

	if (found) {
		_deleteList(pList, pPre, pLoc);
		return true;
	}
	return false;
}

bool traverseList(List* pList, int fromWhere, Element* pDataOut) {
	if (fromWhere == 0 || pList->pos == NULL)
		pList->pos = pList->head;
	else
		pList->pos = pList->pos->link;

	if (pList->pos != NULL) {
		*pDataOut = pList->pos->data;
		return true;
	}else {
		return false;
	}
}

void destroyList(List* pList) {
	ListNode* pDel = NULL, * pNext = NULL;

	for (pDel = pList->head; pDel != NULL; pDel = pNext) {
		pNext = pDel->link;
		free(pDel);
	}

	free(pList);
}