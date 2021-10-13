#pragma warning(disable:4996)
#include "Stack_Array.h"

int main() {
	int origin;
	Stack* b_num;
	int d_num;
	int remain;

	b_num = CreateStack(1000);
	printf("Enter a number: ");
	scanf("%d", &d_num);
	origin = d_num;

	while (1) {
		remain = d_num % 2;
		d_num = d_num / 2;
		Push(b_num, remain);
		if (d_num == 1 || d_num == 0) {
			Push(b_num, d_num);
			break;
		}
	}

	printf("\n\n");
	printf("The binary number of %d: ",origin);

	while (1) {
		int temp = Pop(b_num);
		if (temp == EOF) break;
		printf("%d", temp);
	}
	printf("\n");
	

	return 0;
}