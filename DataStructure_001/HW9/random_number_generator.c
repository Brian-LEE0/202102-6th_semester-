#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, d, temp;
	char filename[100];
	printf("The number of numbers : ");
	scanf("%d", &n);
	printf("The number of digit : ");
	scanf("%d", &d);
	printf("filename : ");
	scanf(" %[^\n]s", filename);

	FILE* fout = fopen(filename, "w");

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		int temp = rand() % (int)pow(10, d);
		printf("%d : %d\n", i, temp);
		fprintf(fout, "%d\n", temp);
	}
	fclose(fout);
	return 0;
}
