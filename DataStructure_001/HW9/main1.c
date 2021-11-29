#include "Binary_Search.h"
#include "Hashed_Search.h"
#include "Sort.h"

int compare(void* argu1, void* argu2);
void BinarySearchfunc(SPACE* space, int list[], int count, int target);
void HashedSearchfunc(SPACE* space, int list[], int count, int target);

int main(int argc, char* argv[]) {
	char temp[100], * result;
	int count = 0, target, menu;
	int list[10000];
	printf("Input file name : ");
	scanf(" %[^\n]s", temp);
	FILE* fin = fopen(temp, "r");
	if (!fin) {
		printf("Error : Cannot match file at this location\n");
		return -1;
	}


	SPACE* space = B_CreateSpace(10000, compare);
	if (!space) {
		printf("Error\n");
		return -2;
	}
	while (result = fgets(temp, 100, fin) != NULL) {
		list[count++] = atoi(temp);
	}
	fclose(fin);
	bubbleSort(list, count);

	printf("Target integer : ");
	scanf("%d", &target);
	printf("\n\nChoose a searching method (Binary : 1, Hashed : 2) : ");
	scanf("%d", &menu);
	switch (menu) {
	case 1: // Binary
		BinarySearchfunc(space, list, count, target);
		break;
	case 2: // Hashed
		HashedSearchfunc(space, list, count, target);
		break;
	}
	return 0;
}

int compare(void* argu1, void* argu2) {
	return (*(element*)argu1) - (*(element*)argu2);
}

void BinarySearchfunc(SPACE* space, int list[], int count, int target) {
	for (int i = 0; i < count; i++){
		B_SaveData(space, list[i]);
	}
	if (B_Search(space, target)) {
		printf("%d is found !\n\n", target);
	}
	else {
		printf("%d is not found !\n\n", target);
	}
	B_DestroySpace(space);
}
void HashedSearchfunc(SPACE* space, int list[], int count, int target) {
	for (int i = 0; i < count; i++) {
		H_SaveData(space, list[i]);
	}
	if (H_Search(space, target)) {
		printf("%d is found !\n\n", target);
	}else{
		printf("%d is not found !\n\n", target);
	}
	H_DestroySpace(space);
}
