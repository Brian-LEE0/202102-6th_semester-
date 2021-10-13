#pragma warning(disable:4996)
#include "Stack_Array.h"
#include <string.h>

char buf[1000];
char buf2[10];
int infixarr[1000];
int postfixarr[1000];
int* int_ptr = '\0';

int* stringToint(Stack* pStack, char* str);
int* infixToPost(Stack* pStack, int* arr);
int postfixEval(Stack* pStack, int* arr);

int main() {
	int result;
	Stack* pStack = CreateStack(1000);

	printf("Arithmetic Expression : ");
	scanf("%[^\n]s", buf);
	int_ptr = stringToint(pStack, buf);
	int_ptr = infixToPost(pStack, infixarr);
	printf("Input : %s\n", buf);
	printf("Post : ");
	


	for (int i = 0; int_ptr[i] != '\0'; i++) {
		if (int_ptr[i] >= 0)	printf("%d ", int_ptr[i]);
		else {
			switch (int_ptr[i]) {
			case -3:printf("+ "); break;
			case -4:printf("- "); break;
			case -5:printf("* "); break;
			case -6:printf("%% "); break;
			}
		}
	}
	printf("\n");
	result = postfixEval(pStack,postfixarr);
	printf("Result : %d\n", result);
	DestroyStack(pStack);
	return 0;
}

int* stringToint(Stack* pStack, char* str) {
	int i = 0, j = 0, k = 0;
	char* ptr = '\0';


	while (1) {
		if (!(str[i] == ' ' || str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '%' || str[i] == '*')) { // if str[i] is int
			buf2[j++] = str[i];
		}
		else {
			if (j != 0) {
				buf2[j] = '\0';
				infixarr[k++] = atoi(buf2); // str[0] = '1', str[1] = '2', str[2] = '3', str[3] = '+' => int_arr[0] = 123, int_arr[1] = -1
				j = 0;
			}

			switch (str[i]) {
			case ' ': // useless
				break;
			case '(': // code_num -5
				infixarr[k++] = -1;
				break;
			case ')':
				infixarr[k++] = -2;
				break;

				/// priority 2
			case '+':
				infixarr[k++] = -3;
				break;
			case '-':
				infixarr[k++] = -4;
				break;

				/// priority 3
			case '*':
				infixarr[k++] = -5;
				break;
			case '%':
				infixarr[k++] = -6;
				break;
			default:
				printf("Error : You can only input integer and +-%%*\n");
				DestroyStack(pStack);
				exit(1);
			}

		}
		if (str[i++] == '\0') {
			buf2[j] = '\0';
			infixarr[k++] = atoi(buf2);
			j = 0;
			break;
		}
	}

	return infixarr;
}

int* infixToPost(Stack* pStack, int* arr) {
	bool double_operand = false;
	bool double_operator = false;
	int open_par = 0;
	int close_par = 0;
	int j = 0;

	for (int i = 0; arr[i] != '\0';) {

		if (arr[i] > 0) { // operand
			postfixarr[j++] = arr[i++];
			if (double_operand == true) {
				printf("Error : Check the binary expression !\n");
				DestroyStack(pStack); // Destroy Stack;
				exit(1);
			}
			double_operand = true;
			double_operator = false;
			
		}
		else {
				switch (arr[i++]) {
				case -1: // code_num -5
					Push(pStack,-1); // push("(");
					open_par++;
					break;
				case -2:
					while (Top(pStack) != -1 && Top(pStack) != '\0') postfixarr[j++] = Pop(pStack);
					if (Top(pStack) == -1) Pop(pStack);
					close_par++;
					break;


					/// priority 2
				case -3:
					if (Top(pStack) <= -3 && Top(pStack) >= -6) postfixarr[j++] = Pop(pStack);
					Push(pStack ,-3); // push("+");
					if (double_operator == true) {
						printf("Error : Check the binary expression !\n");
						DestroyStack(pStack); // Destroy Stack;
						return;
					}
					double_operator = true;
					break;
				case -4:
					if (Top(pStack) <= -3 && Top(pStack) >= -6) postfixarr[j++] = Pop(pStack);
					Push(pStack, -4); // push("-");
					if (double_operator == true) {
						printf("Error : Check the binary expression !\n");
						DestroyStack(pStack); // Destroy Stack;
						exit(1);
					}
					double_operator = true;
					break;


					/// priority 3
				case -5:
					if (Top(pStack) <= -5 && Top(pStack) >= -6) postfixarr[j++] = Pop(pStack);
					Push(pStack ,-5); // push("*");
					if (double_operator == true) {
						printf("Error : Check the binary expression !\n");
						DestroyStack(pStack); // Destroy Stack;
						exit(1);
					}
					double_operator = true;
					break;
				case -6:
					if (Top(pStack) <= -5 && Top(pStack) >= -6) postfixarr[j++] = Pop(pStack);
					Push(pStack ,-6); // push("/");
					if (double_operator == true) {
						printf("Error : Check the binary expression !\n");
						DestroyStack(pStack); // Destroy Stack;
						exit(1);
					}
					double_operator = true;
					break;
				default:
					printf("error\n");
					DestroyStack(pStack);
					exit(1);
				}
				
				double_operand = false;
		}
	}//3*((67-60)*4 -20)


	if (close_par != open_par) {
		printf("Error : Check the pairs of Parenthesis !\n");
		DestroyStack(pStack); // Destroy Stack;
		exit(1);
	}
	while (Top(pStack) != EOF) postfixarr[j++] = Pop(pStack);
	postfixarr[j] = '\0';
	return postfixarr;
}

int postfixEval(Stack* pStack, int* arr) {
	int result;
	int a, b;
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] >= 0) {
			Push(pStack,arr[i]);
		}
		else {
			b = Pop(pStack); a = Pop(pStack);
			switch (arr[i]) {
			case -3:Push(pStack,a + b); break;
			case -4:Push(pStack, a - b); break;
			case -5:Push(pStack, a * b); break;
			case -6:Push(pStack, a % b); break;
			}
		}
	}
	result = Pop(pStack);
	return result;
}