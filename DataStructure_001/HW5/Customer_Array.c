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
		case 0://0�� ����������
			if (isFull(queue)) {
				printf("Queue is full !");
				break;
			}
			printf("Customer : ");
			scanf(" %[^\n]s", name); // �̸��Է�
			
			EnQueue(queue, name);
			printf("The current status of Queue : ");
			printallQueue(queue); // Queue ��⿭ ��� ����ϴ� �Լ�
			break;
		case 1://1�� ����������
			if (isEmpty(queue)) {
				printf("Queue is empty !");
				break;
			}
			printf("Customer dequeued : %s\n", DeQueue(queue, name));
			
			printf("The current status of Queue : ");
			printallQueue(queue);
			break;

		case 2://2�� ����������
			DistroyQueue(queue); // QueueNode�� ��ȯ�ϰ� �� �������� Queue�� ��ȯ��
			return 0;
		}
		
			
		printf("\n\n");			

	}
	

	
}