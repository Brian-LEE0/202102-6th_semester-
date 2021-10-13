#pragma warning(disable:4996)
#include "Stack_Link.h"

int main() {

	Stack* arr;
	int ch = 0;
	int temp;

	arr = CreateStack(1000);

	while (1) {
		printf("Enter a number: <Ctrl+d> to stop: ");
		ch = scanf("%d", &temp);
		if (ch == EOF) break;
		Push(arr, temp);
	}

	printf("\n");
	printf("The List of numbers reversed:\n");

	while (1) {
		temp = Pop(arr);
		if (temp == EOF) break;
		printf("%d\n", temp);
	}

	DestroyStack(arr);

	return 0;
}