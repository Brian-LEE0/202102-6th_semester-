#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1000

int compare(void* argu1, void* argu2);

typedef char element;

typedef struct {
	int count; // Number of vertices
	int arc_count; // Number of edges
	struct Matrix** matrix;
	struct Vertex* first;
	int (*compare)(void* argu1, void* argu);

}GRAPH;


typedef struct Vertex {
	struct Vertex* pPreVertex;
	struct Vertex* pNextVertex;
	void* dataPtr;
	int distance;
	int processed;
}VERTEX;

typedef struct Matrix {
	struct Vertex* source;
	struct Vertex* destination;
	int processed;
	int Arc;
}MATRIX;


void processed_State_Initialize(GRAPH* graph);

GRAPH* CreateGraph(int c) {
	GRAPH* pNewGraph = (GRAPH*)malloc(sizeof(GRAPH));
	if (pNewGraph == NULL) {
		return NULL;
	}
	pNewGraph->count = 0;
	pNewGraph->matrix = NULL;
	pNewGraph->first = NULL;
	pNewGraph->compare = compare;

	return pNewGraph;
}

MATRIX* _retrieveMatrix(GRAPH* graph, void* data, void* data2) { // find the vertex address
	for (int s = 0; s < graph->count; s++) {
		for (int d = 0; d < graph->count; d++) {

			if ((!(graph->compare)(graph->matrix[s][d].source->dataPtr, data)) && (!(graph->compare)(graph->matrix[s][d].destination->dataPtr, data2))) {

				return &(graph->matrix[s][d]);
			}
		}
	}
	return NULL;
}

VERTEX* _retrieveVertex(GRAPH* graph, void* data) { // find the vertex address
	VERTEX* temp = graph->first;
	if (temp == NULL) {
		return NULL;
	}
	while (temp != NULL) {
		if (!(*graph->compare)(temp->dataPtr, data)) {
			return temp;
		}
		else {
			temp = temp->pNextVertex;
		}
	}

	return NULL;
}

void InsertVertex(GRAPH* graph, void* data) {
	graph->count++;
	MATRIX** newMatrix = (MATRIX**)malloc(sizeof(MATRIX*) * (graph->count));
	if (newMatrix == NULL) {
		return;
	}
	for (int i = 0; i < graph->count; i++) {
		*(newMatrix + i) = (MATRIX*)malloc(sizeof(MATRIX) * (graph->count));
		if (*(newMatrix + i) == NULL) {
			return;
		}
	}// make N by N matrix 

	VERTEX* newVertex = (VERTEX*)malloc(sizeof(VERTEX));
	if (newVertex == NULL)return;
	VERTEX* temp;
	newVertex->dataPtr = data;
	newVertex->pPreVertex = NULL;
	newVertex->pNextVertex = NULL;
	newVertex->distance = INF;
	newVertex->processed = INF;
	if (graph->first == NULL) {
		graph->first = newVertex;
	}
	else {
		temp = graph->first;
		while (temp->pNextVertex != NULL) {
			temp = temp->pNextVertex;
		}
		temp->pNextVertex = newVertex;
	}


	if (graph->matrix == NULL) {
		graph->matrix = newMatrix;
		newMatrix[0][0].source = newVertex;
		newMatrix[0][0].destination = newVertex;
		newMatrix[0][0].processed = 0;
		newMatrix[0][0].Arc = INF;
	}
	else {
		for (int i = 0; i < (graph->count - 1); i++) {
			for (int j = 0; j < (graph->count - 1); j++) {
				newMatrix[i][j] = graph->matrix[i][j];
			}
		}
		for (int i = 0; i < graph->count - 1; i++) {
			newMatrix[graph->count - 1][i].source = newVertex;
			newMatrix[graph->count - 1][i].destination = newMatrix[graph->count - 2][i].destination;
			newMatrix[graph->count - 1][i].processed = INF;
			newMatrix[graph->count - 1][i].Arc = INF;

			newMatrix[i][graph->count - 1].source = newMatrix[i][graph->count - 2].source;
			newMatrix[i][graph->count - 1].destination = newVertex;
			newMatrix[i][graph->count - 1].processed = INF;
			newMatrix[i][graph->count - 1].Arc = INF;
		}

		newMatrix[graph->count - 1][graph->count - 1].source = newVertex;
		newMatrix[graph->count - 1][graph->count - 1].destination = newVertex;
		newMatrix[graph->count - 1][graph->count - 1].processed = INF;
		newMatrix[graph->count - 1][graph->count - 1].Arc = INF;

		for (int i = 0; i < graph->count - 1; i++)free(graph->matrix[i]);
		free(graph->matrix);
		graph->matrix = newMatrix;
	}
	return;
}

void InsertEdge(GRAPH* graph, void* data1, void* data2, int weight) { // data1 == source data2 == direction;
	MATRIX* mt = _retrieveMatrix(graph, data1, data2);
	if (mt == NULL) return;
	mt->Arc = weight;
	graph->arc_count++;
	return;
}


void DeleteEdge(GRAPH* graph, void* data1, void* data2) {
	MATRIX* mt = _retrieveMatrix(graph, data1, data2);
	if (mt == NULL) return;
	mt->Arc = INF;
	graph->arc_count--;
	return;
}


//void DeleteVertex(GRAPH* graph, void* data) {

//} // Not need;

void traversalGraph(GRAPH* graph) {
	if (graph == NULL || graph->matrix == NULL) return;
	for (int s = 0; s < graph->count; s++) {
		printf("%c : ", *(element*)graph->matrix[s][0].source->dataPtr);
		for (int d = 0; d < graph->count; d++) {
			if (graph->matrix[s][d].Arc != INF) {
				printf("%c (%d) ", *(element*)graph->matrix[s][d].destination->dataPtr, graph->matrix[s][d].Arc);
			}
		}
		printf("\n");
	}
	return;
}

void DestroyGraph(GRAPH* graph) {
	if (graph == NULL || graph->matrix == NULL) return;
	VERTEX* temp = graph->first, * temp2;

	while (temp) {
		temp2 = temp->pNextVertex;
		free(temp);
		temp = temp2;
	}
	for (int i = 0; i < graph->count; i++) free(graph->matrix[i]);
	free(graph->matrix);
	return;
}

int compare(void* argu1, void* argu2) {
	return (*(element*)argu1) - (*(element*)argu2);
}

void MinimumSpanningTree(GRAPH* graph, void* rootdataPtr, void (*process)(void* dataPtr, void* dataPtr2, int weight))
{
	VERTEX* startVertex = _retrieveVertex(graph, rootdataPtr);
	if (!startVertex) {
		return;
	}
	startVertex->processed = 0;
	VERTEX* temp = NULL;
	MATRIX* tempMt = NULL;
	int count = 0, compare = INF;

	while (count++ < (graph->count - 1)) {
		temp = graph->first;
		while (temp) {
			if (!temp->processed) {
				MATRIX* mt = _retrieveMatrix(graph, temp->dataPtr, graph->first->dataPtr);
				for (int i = 0; i < graph->count; i++) {
					if ((mt + i)->Arc < INF && (mt+i)->processed == INF && (mt+i)->destination->processed == INF) {
						if ((mt + i)->Arc < compare) {
							compare = (mt + i)->Arc;
							tempMt = (mt + i);
						}
					}
				}
			}			
			temp = temp->pNextVertex;
		}
		if (tempMt) {
			tempMt->destination->processed = 0;
			tempMt->processed = 0;
			printf("%c %c (%d)\n", *(element*)tempMt->source->dataPtr, *(element*)tempMt->destination->dataPtr, tempMt->Arc);
			compare = INF;
			tempMt = NULL;
		}
		else {
			printf("No spanning tree\n");
			return;
		}
	}

	processed_State_Initialize(graph);
	return;
}

void ShortestPath(GRAPH* graph, void* rootdataPtr,void (*process)(void* dataPtr, void* dataPtr2, int weight)) {

	VERTEX* startVertex = _retrieveVertex(graph, rootdataPtr);
	if (!startVertex) {
		return;
	}
	startVertex->processed = 0;
	startVertex->distance = 0;
	VERTEX* temp = NULL;
	MATRIX* tempMt = NULL;
	int count = 0, compare = INF;

	while (count++ < graph->count) {
		temp = graph->first;
		while (temp) {
			if (!temp->processed) {
				MATRIX* mt = _retrieveMatrix(graph, temp->dataPtr, graph->first->dataPtr);
				for (int i = 0; i < graph->count; i++) {
					if ((mt + i)->Arc < INF && (mt + i)->processed == INF && (mt+i)->destination->processed) {
						if ((mt + i)->Arc < ((mt + i)->destination->distance - (mt+i)->source->distance)) {
							(mt + i)->destination->distance = (mt + i)->Arc + (mt+i)->source->distance;
						}
						if ((!(mt + i)->source->processed) && ((mt + i)->Arc + (mt + i)->source->distance) < compare) {
							compare = (mt + i)->Arc + (mt + i)->source->distance;
							tempMt = (mt + i);
						}
					}
				}
			}
			temp = temp->pNextVertex;
		}
		temp = graph->first;
		while (temp) {
			if ((*graph->compare)(rootdataPtr, temp->dataPtr)) {
				(*process)(rootdataPtr, temp->dataPtr, temp->distance);
			}			
			temp = temp->pNextVertex;
		}
		if (tempMt) {
			tempMt->destination->processed = 0;
			tempMt->processed = 0;
		}

		compare = INF;
		tempMt = NULL;		
		printf("\n");
		
	}

	processed_State_Initialize(graph);
	return;
}

void processed_State_Initialize(GRAPH* graph) {
	if (graph->first == NULL || graph == NULL || graph->matrix == NULL) return;
	int matrix_size = graph->count * graph->count;
	VERTEX* temp = graph->first ;
	while (temp) {
		temp->processed = INF;
		temp->distance = INF;
		temp = temp->pNextVertex;
	}
	for (int i = 0; i < graph->count; i++) {
		for (int j = 0; j < graph->count; j++) {
			graph->matrix[i][j].processed = INF;
		}
	}
}