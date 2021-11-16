#include "Ad_Matrix3.h"

#define MAX_LAN 10
#define MAX_ARC 100

void print(void* dataPtr, void* dataPtr2, int weight);

int main() {
	char str[100];
	char buf[MAX_ARC][MAX_LAN];
	char buf2[100];
	char filename[100];
	char start, temp;
	int insert = 0;
	int count = 0;
	FILE* fpin;
	GRAPH* graph = CreateGraph(1);
	if (!graph) return -2;

	str[0] = '\0';
	printf("File name of graph : ");
	scanf(" %[^\n]s", filename);
	fpin = fopen(filename, "r");

	if (fpin == NULL) {
		return -1;
	}
	printf("\nThe graph is : \n");
	while (fgets(buf2, MAX_LAN, fpin) != NULL) {
		if (count == 0) { // starting point;
			count++;
		}
		else {
			for (unsigned int i = 0; i < strlen(str) + 1; i++) {
				if (insert == false) {
					if (str[i] == '\0') {
						str[i] = buf2[0];
						str[i + 1] = '\0';
						break;
					}
					if (str[i] == buf2[0]) {
						break;
					}
					if (str[i] > buf2[0]) {
						temp = str[i];
						str[i] = buf2[0];
						insert = true;
					}
				}
				else {
					buf2[0] = str[i];
					str[i] = temp;
					temp = buf2[0];
				}
			}
			insert = false;
			for (unsigned int i = 0; i < strlen(str) + 1; i++) {
				if (insert == false) {
					if (str[i] == '\0') {
						str[i] = buf2[2];
						str[i + 1] = '\0';
						break;
					}
					if (str[i] == buf2[2]) {
						break;
					}
					if (str[i] > buf2[2]) {
						temp = str[i];
						str[i] = buf2[2];
						insert = true;
					}
				}
				else {
					buf2[2] = str[i];
					str[i] = temp;
					temp = buf2[2];
				}
			}
			insert = false;
		}
	} //ABCDEFGH 정렬

	for (unsigned int i = 0; i < strlen(str); i++) {
		InsertVertex(graph, str + i);
	} // Vertex 삽입


	rewind(fpin);
	count = 0;

	while (fgets(buf[count], MAX_LAN, fpin) != NULL) {
		if (count == 0) { // starting point;
			start = buf[count][0];
			count++;
		}
		else {
			InsertEdge(graph, buf[count], buf[count] + 2, (buf[count][4] - '0')); // Edge 삽입
			InsertEdge(graph, buf[count] + 2, buf[count], (buf[count][4] - '0'));
			// undirected graph 이기 때문에 반대로도 Edge 삽입
			count++;
		}
	}
	fclose(fpin);

	traversalGraph(graph);
	printf("\n\nMinimum spanning tree : \n");
	MinimumSpanningTree(graph, &start, print);

	printf("\n\nShortest path from %c  : \n\n",start);
	ShortestPath(graph, &start, print);
	DestroyGraph(graph);

	printf("\n\n");
	return 0;
}

void print(void* dataPtr, void* dataPtr2, int weight) {
	printf("%c %c (%d)\n", *(char*)dataPtr, *(char*)dataPtr2, weight);
}
