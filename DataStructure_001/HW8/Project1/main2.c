//#include "Ad_List.h"
#include "Ad_Matrix.h"

#define MAX_LAN 10
#define MAX_ARC 100

void printchar(void* dataPtr);

int main() {
	char str[100];
	char buf[MAX_ARC][MAX_LAN];
	char buf2[100];
	char start,temp;
	int insert = 0;
	int count = 0;
	FILE* fpin;
	GRAPH* graph = CreateGraph(1);
	if (!graph) return -2;

	str[0] = '\0';

	fpin = fopen("input2.txt", "r");
	if (fpin == NULL) return -1;

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
	} //ABCDEFGH Á¤·Ä

	for (unsigned int i = 0; i < strlen(str); i++) {
		InsertVertex(graph, str+i);
	} // Vertex »ðÀÔ


	rewind(fpin);
	count = 0;

	while (fgets(buf[count], MAX_LAN, fpin) != NULL) {
		if (count == 0) { // starting point;
			start = buf[count][0];
			count++;
		}
		else {
			InsertEdge(graph, buf[count], buf[count] + 2); // Edge »ðÀÔ
			count++;
		}
	}
	fclose(fpin);

	traversalGraph(graph);
	printf("\n\nDepth First Traversal : ");
	DepthFirstTraversal(graph,&start, printchar);
	printf("\nBreadth First Traversal : ");
	BreadthFirstTraversal(graph,&start, printchar);	
	DestroyGraph(graph);

	printf("\n\n");
	return 0;
}

void printchar(void* dataPtr){
	printf("%c ", *(char*)dataPtr);
}
