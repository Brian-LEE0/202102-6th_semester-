#pragma warning(disable:4996)
#include "Queue_Array.h"

int main() {
	int num;
	char name[100];
	Queue* queue = CreateQueue(100);
	while (1) {		
		printf("in (0), out (1), exit (2) : ");
		scanf("%d", &num);		

		switch (num) {
		case 0://0을 선택했을때
			if (isFull(queue)) {
				printf("Queue is full !");
				break;
			}
			printf("Customer : ");
			scanf(" %[^\n]s", name); // 이름입력
			
			EnQueue(queue, name);
			printf("The current status of Queue : ");
			printallQueue(queue); // Queue 대기열 모두 출력하는 함수
			break;
		case 1://1을 선택했을때
			if (isEmpty(queue)) {
				printf("Queue is empty !");
				break;
			}
			printf("Customer dequeued : %s\n", DeQueue(queue, name));
			
			printf("The current status of Queue : ");
			printallQueue(queue);
			break;

		case 2://2을 선택했을때
			DistroyQueue(queue); // QueueNode를 반환하고 맨 마지막에 Queue를 반환함
			return 0;
		}
		
			
		printf("\n\n");			

	}
	

	
}