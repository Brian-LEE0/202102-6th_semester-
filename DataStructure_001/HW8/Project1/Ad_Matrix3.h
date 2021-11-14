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
	int processed;
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
		*(newVertex + i) = (VERTEX*)malloc(sizeof(VERTEX) * (graph->count));
		if (*(newVertex + i) == NULL) {
			return;
		}
	}

	if (graph->vt == NULL) {
		graph->vt = newVertex;
		newVertex[0][0].source = data;
		newVertex[0][0].destination = data;
		newVertex[0][0].processed = newVertex[0][0].processed2 = 0;
		newVertex[0][0].Arc = 99;
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
			newVertex[graph->count - 1][i].processed = newVertex[graph->count - 1][i].processed2 = 99;
			newVertex[graph->count - 1][i].Arc = 99;

			newVertex[i][graph->count - 1].source = newVertex[i][graph->count - 2].source;
			newVertex[i][graph->count - 1].destination = data;
			newVertex[i][graph->count - 1].processed = newVertex[i][graph->count - 1].processed2 = 99;
			newVertex[i][graph->count - 1].Arc = 99;
		}

		newVertex[graph->count - 1][graph->count - 1].source = data;
		newVertex[graph->count - 1][graph->count - 1].destination = data;
		newVertex[graph->count - 1][graph->count - 1].processed = newVertex[graph->count - 1][graph->count - 1].processed2 = 99;
		newVertex[graph->count - 1][graph->count - 1].Arc = 99;

		for (int i = 0; i < graph->count - 1; i++)free(graph->vt[i]);
		free(graph->vt);
		graph->vt = newVertex;
	}
	return;
}

void InsertEdge(GRAPH* graph, void* data1, void* data2, int weight) { // data1 == source data2 == direction;
	VERTEX* vt = _retrieveVector(graph, data1, data2);
	vt->Arc = weight;
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
			if (graph->vt[s][d].Arc != 99) {
				printf("%c (%d) ", *(element*)graph->vt[s][d].destination, graph->vt[s][d].Arc);
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

void MinimumSpanningTree(GRAPH* graph, void* rootdataPtr, void (*process)(void* dataPtr, void* dataPtr2, int weight))
{
	char T[100][2];/* T is set of tree edges */
	element TV[100];/*TV is set of tree vertices */
	T[0][0] = '\0';
	TV[0] = '\0';
	int count1 = 0, count2 = 0;
	int standard = 99;
	VERTEX* StartingVertex = _retrieveVector(graph, rootdataPtr, graph->first);
	VERTEX* buf;
	/* start with vertex 0 and no edges */
	while (count1<(graph->count-1)/*T contains less than n - 1 edges*/) {
		for (int i = 0; i < graph->count; i++) {
			if (standard > (StartingVertex + i)->Arc) {
				buf = (StartingVertex + i);
				standard = (StartingVertex + i)->Arc;
			}
		}
		if (there is no such edge)
			break;
		add v to TV;
		add(u, v) or (v, u) to T;
		T++
	}
	if (T contains fewer than n - 1 edges)
		printf(¡°No spanning tree\n¡±);
}

bool is_selected(void* data, element* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (*(element*)data == str[i]) {
			return true;
		}
	}
	return false;
}