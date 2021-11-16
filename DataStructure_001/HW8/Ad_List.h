#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graph_Queue.h"

int compare(void* argu1, void* argu2);

typedef char element;

typedef struct {
	int count;
	struct vertex* first;
	int (*compare)(void* argu1, void* argu);
}GRAPH;

typedef struct vertex {
	struct vertex* pNewVertex;
	void* dataPtr;
	short processed;
	short processed2;
	struct arc* pArc;
}VERTEX;

typedef struct arc {
	struct vertex* destination;
	struct arc* pNextArc;
}ARC;

GRAPH* CreateGraph(int c) {
	GRAPH* pNewGraph = (GRAPH*)malloc(sizeof(GRAPH));
	if (pNewGraph == NULL) {
		return NULL;
	}
	pNewGraph->count = 0;
	pNewGraph->first = NULL;
	pNewGraph->compare = compare;

	return pNewGraph;
}

VERTEX* _retrieveVertex(GRAPH* graph, void* data, VERTEX** pvtPre) { // find the vertex address
	VERTEX* temp = NULL, * tempPre = NULL;
	if (graph == NULL || graph->first == NULL) {
		return NULL;
	}

	tempPre = temp = graph->first;
	for (int i = 0; i < graph->count; i++) {
		if ((graph->compare)(data, temp->dataPtr) == 0) {
			*pvtPre = tempPre;
			return temp;
		}
		tempPre = temp;
		temp = temp->pNewVertex;
	}
	return NULL;
}

void InsertVertex(GRAPH* graph, void* data) {
	VERTEX* temp;

	if (_retrieveVertex(graph, data, &temp) != NULL) return;

	VERTEX* pNewVertex = (VERTEX*)malloc(sizeof(VERTEX));
	if (pNewVertex == NULL) {
		return;
	}

	pNewVertex->pNewVertex = NULL;
	pNewVertex->dataPtr = data;
	pNewVertex->processed = pNewVertex->processed2 = 0;
	pNewVertex->pArc = NULL;

	if (graph->first == NULL) {
		graph->first = pNewVertex;
	}
	else {
		VERTEX* tempPre = NULL;
		VERTEX* tempNow = NULL;
		tempNow = graph->first;
		if ((graph->compare)(graph->first->dataPtr, data) > 0) {
			graph->first = pNewVertex;
			pNewVertex->pNewVertex = tempNow;
			graph->count++;
			return;
		}
		for (int i = 0; i < (graph->count - 1); i++) {
			tempPre = tempNow;
			tempNow = tempNow->pNewVertex;

			if ((graph->compare)(tempNow->dataPtr, data) > 0) {
				tempPre->pNewVertex = pNewVertex;
				pNewVertex->pNewVertex = tempNow;
				graph->count++;
				return;
			}
		}
		tempNow->pNewVertex = pNewVertex;
	}
	graph->count++;
	return;
}

void InsertEdge(GRAPH* graph, void* data1, void* data2) { // data1 == source data2 == direction;
	VERTEX* temp = NULL;
	VERTEX* vt1 = _retrieveVertex(graph, data1, &temp);
	VERTEX* vt2 = _retrieveVertex(graph, data2, &temp);
	if (vt1 == NULL || vt2 == NULL) return;

	ARC* tempArc = NULL;

	/*ARC* arc1 = (ARC*)malloc(sizeof(ARC));
	if (arc1 == NULL) return;
	arc1->destination = vt1;
	arc1->pNextArc = NULL;*///if undirected graph

	ARC* arc2 = (ARC*)malloc(sizeof(ARC));
	if (arc2 == NULL) return;
	arc2->destination = vt2;
	arc2->pNextArc = NULL;

	if (vt1->pArc == NULL) {
		vt1->pArc = arc2;
	}
	else {
		tempArc = vt1->pArc;
		while (1) {
			if (tempArc->pNextArc == NULL) {
				tempArc->pNextArc = arc2;
				break;
			}
			else {
				tempArc = tempArc->pNextArc;
			}
		}
	}

	/*if (vt2->pArc == NULL) {
		vt2->pArc = arc1;
	}
	else {
		tempArc = vt2->pArc;
		while (1) {
			if (tempArc->pNextArc == NULL) {
				tempArc->pNextArc = arc1;
				break;
			}
			else {
				tempArc = tempArc->pNextArc;
			}
		}
	}*/ //if undirected graph
	return;

}


void _DeleteEdge(GRAPH* graph, VERTEX* origin_vt, VERTEX* delete_vt) {
	ARC* tempPre = NULL, * tempNow = NULL;
	tempPre = tempNow = origin_vt->pArc;
	if (origin_vt->pArc->destination == delete_vt) {
		origin_vt->pArc = tempNow->pNextArc;
	}
	while (tempNow != NULL) {
		if (!(graph->compare)(tempNow->destination->dataPtr, delete_vt->dataPtr)) {
			tempPre->pNextArc = tempNow->pNextArc;
			free(tempNow);
			return;
		}
		else {
			tempPre = tempNow;
			tempNow = tempNow->pNextArc;
		}
	}
	return;
}


void DeleteVertex(GRAPH* graph, void* data) {
	VERTEX* pvtPre = NULL;
	VERTEX* vt = _retrieveVertex(graph, data, &pvtPre);
	if (graph == NULL || vt == NULL) return;
	ARC* temp = NULL, * temp2 = NULL;
	VERTEX* tempVT = NULL;
	/*temp = vt->pArc;
	while (temp != NULL) {
		printf("vt : %c des : %c\n", *(element*)(vt->dataPtr), *(element*)(temp->destination->dataPtr));
		_DeleteEdge(graph, temp->destination, vt);
		temp = temp->pNextArc;
	}*/ //if undirected graph
	temp = vt->pArc;
	while (temp != NULL) {
		temp2 = temp->pNextArc;
		_DeleteEdge(graph, vt, temp->destination);
		temp = temp2;
	}

	pvtPre->pNewVertex = vt->pNewVertex;
	free(vt);
	graph->count--;
	return;
}

void traversalGraph(GRAPH* graph) {
	VERTEX* tempNow = NULL;
	ARC* temp = NULL;
	tempNow = graph->first;
	for (int i = 0; i < graph->count; i++) {
		printf("%c : ", *(element*)(tempNow->dataPtr));
		temp = tempNow->pArc;
		while (temp != NULL) {
			printf("%c ", *(element*)temp->destination->dataPtr);
			temp = temp->pNextArc;
		}
		printf("\n");
		tempNow = tempNow->pNewVertex;
	}
}

void DestroyGraph(GRAPH* graph) {
	VERTEX* t1, * t2;
	t1 = graph->first;
	while (graph->count != 0) {
		t2 = t1->pNewVertex;
		DeleteVertex(graph, t1->dataPtr);
		graph->first = t1 = t2;
	}
	free(graph);
}

int compare(void* argu1, void* argu2) {
	return (*(element*)argu1) - (*(element*)argu2);
}

void DepthFirstTraversal(GRAPH* graph, void* rootdataPtr, void (*process)(void* dataPtr))
{
	VERTEX* temp;
	VERTEX* root = _retrieveVertex(graph, rootdataPtr, &temp);

	ARC* arc = NULL;
	if (root->processed)
		return;
	(*process)(root->dataPtr);
	root->processed = true;
	for (arc = root->pArc; arc != NULL; arc = arc->pNextArc) {
		if (!arc->destination->processed)
			DepthFirstTraversal(graph, arc->destination->dataPtr, process);
	}
}

void BreadthFirstTraversal(GRAPH* graph, void* rootdataPtr, void (*process)(void* dataPtr))
{
	VERTEX* temp;
	VERTEX* root = _retrieveVertex(graph, rootdataPtr, &temp);

	Queue* queue = NULL;
	ARC* arc = NULL;
	if (root == NULL)
		return;
	queue = CreateQueue(100);
	while (root) {

		for (arc = root->pArc; arc != NULL; arc = arc->pNextArc) {
			EnQueue(queue, (void*)(arc->destination));
		}
		if (!root->processed2) {
			(*process)(root->dataPtr);
			root->processed2 = true;
		}

		if (!isEmpty(queue)) {
			root = (VERTEX*)DeQueue(queue);
		}
		else {
			root = NULL;
		}


	}
}