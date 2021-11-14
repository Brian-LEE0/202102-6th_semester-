#pragma warning (disable : 6386)
#pragma warning (disable : 6385)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graph_Queue.h"

int compare(void* argu1, void* argu2);

typedef char element;

typedef struct {
	int count;
	struct vertex** vt;
	void* first;
	int (*compare)(void* argu1, void* argu);
	
}GRAPH;

typedef struct vertex {
	void* source;
	void* destination;
	short processed;
	short processed2;
	int Arc;
}VERTEX;

GRAPH* CreateGraph(int c) {
	GRAPH* pNewGraph = (GRAPH*)malloc(sizeof(GRAPH));
	if (pNewGraph == NULL) {
		return NULL;
	}
	pNewGraph->count = 0;
	pNewGraph->vt = NULL;
	pNewGraph->first = NULL;
	pNewGraph->compare = compare;

	return pNewGraph;
}

VERTEX* _retrieveVector(GRAPH* graph, void* data, void* data2) { // find the vertex address
	for (int s = 0; s < graph->count; s++) {
		for (int d = 0; d < graph->count; d++) {

			if ((!(graph->compare)(graph->vt[s][d].source, data)) && (!(graph->compare)(graph->vt[s][d].destination, data2))) {
				
				return &(graph->vt[s][d]);
			}
		}
	}
	return NULL;
}

void InsertVertex(GRAPH* graph, void* data) {
	graph->count++;
	VERTEX** newVertex = (VERTEX**)malloc(sizeof(VERTEX*) * (graph->count));
	if (newVertex == NULL) {
		return;
	}
	for (int i = 0; i < graph->count; i++) {
		*(newVertex+i) = (VERTEX*)malloc(sizeof(VERTEX) * (graph->count));
		if (*(newVertex+i) == NULL) {
			return;
		}
	}

	if (graph->vt == NULL) {
		graph->vt = newVertex;
		newVertex[0][0].source = data;
		newVertex[0][0].destination = data;
		newVertex[0][0].processed = newVertex[0][0].processed2 = false;
		newVertex[0][0].Arc = 0;
		graph->first = data;
	}
	else {
		for (int i = 0; i < (graph->count - 1); i++) {
			for (int j = 0; j < (graph->count - 1); j++) {
				newVertex[i][j] = graph->vt[i][j];
			}
		}
		for (int i = 0; i < graph->count - 1; i++) {
			newVertex[graph->count - 1][i].source = data;
			newVertex[graph->count - 1][i].destination = newVertex[graph->count - 2][i].destination;
			newVertex[graph->count - 1][i].processed = newVertex[graph->count - 1][i].processed2 = false;
			newVertex[graph->count - 1][i].Arc = 0;

			newVertex[i][graph->count - 1].source = newVertex[i][graph->count - 2].source;
			newVertex[i][graph->count - 1].destination = data;
			newVertex[i][graph->count - 1].processed = newVertex[i][graph->count - 1].processed2 = false;
			newVertex[i][graph->count - 1].Arc = 0;
		}

		newVertex[graph->count - 1][graph->count - 1].source = data;
		newVertex[graph->count - 1][graph->count - 1].destination = data;
		newVertex[graph->count - 1][graph->count - 1].processed = newVertex[graph->count - 1][graph->count - 1].processed2 = false;
		newVertex[graph->count - 1][graph->count - 1].Arc = 0;

		for (int i = 0; i < graph->count - 1; i++)free(graph->vt[i]);
		free(graph->vt);
		graph->vt = newVertex;
	}
	return;
}

void InsertEdge(GRAPH* graph, void* data1, void* data2) { // data1 == source data2 == direction;
	VERTEX* vt = _retrieveVector(graph, data1, data2);
	vt->Arc = true;
	return;
}


void DeleteEdge(GRAPH* graph, void* data1, void* data2) {
	VERTEX* vt = _retrieveVector(graph, data1, data2);
	vt->Arc = false;
	return;
}


//void DeleteVertex(GRAPH* graph, void* data) {

//} // Not need;

void traversalGraph(GRAPH* graph) {
	for (int s = 0; s < graph->count; s++) {
		printf("%c : ", *(element*)graph->vt[s][0].source);
		for (int d = 0; d < graph->count; d++) {
			if (graph->vt[s][d].Arc) {
				printf("%c ", *(element*)graph->vt[s][d].destination);
			}
		}
		printf("\n");
	}
	return;
}

void DestroyGraph(GRAPH* graph) {
	if (graph->vt == NULL) return;
	for (int i = 0; i < graph->count; i++) free(graph->vt[i]);
	free(graph->vt);
	return;
}

int compare(void* argu1, void* argu2) {
	return (*(element*)argu1) - (*(element*)argu2);
}

void DepthFirstTraversal(GRAPH* graph, void* rootdataPtr, void (*process)(void* dataPtr))
{
	VERTEX* root = _retrieveVector(graph, rootdataPtr, graph->first);
	if (!root)
		return;
	if (root->processed)
		return;
	(*process)(root->source);
	root->processed = true;
	for (int i = 0; i < graph->count; i++) {
		if ((root + i)->Arc && !((root + i)->processed)) {
			DepthFirstTraversal(graph, (root+i)->destination, process);
		}
	}
	return;
}

void BreadthFirstTraversal(GRAPH* graph, void* rootdataPtr, void (*process)(void* dataPtr))
{
	VERTEX* root = _retrieveVector(graph, rootdataPtr, graph->first);
	if (!root) return;
	VERTEX* temp;
	Queue* queue = CreateQueue(100);
	if (!queue) return;
	while (root) {
		for (int i = 0; i < graph->count; i++) {
			if ((root + i)->Arc) {
				temp = _retrieveVector(graph, (root + i)->destination, graph->first);
				if (!temp->processed2) {
					EnQueue(queue, (void*)temp);
				}
			}
		}
		if (!root->processed2) {
			(*process)(root->source);
			root->processed2 = true;
		}

		if (!isEmpty(queue)) {
			root = (VERTEX*)DeQueue(queue);
		}
		else {
			return;
		}

	}

}