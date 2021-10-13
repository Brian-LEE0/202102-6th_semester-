#pragma warning(disable:4996)
#include "List_Link.h"

void showList(List* pList);

int main() {
	int num, result;
	List* list = createList(100);
	while (1) {
		printf("In (0), Search (1), Out (2), Exit (3) : ");
		scanf("%d", &num);

		switch (num) {
		case 0://0을 선택했을때
			printf("In : ");
			scanf("%d", &num);
			result = addNodeList(list, num);
			if (result != true) {
				if (result == false) printf("My List already has %d.\n", num);
				else printf("Error : My List is Full.\n");
				showList(list);
				break;
			}
			showList(list);
			break;
		case 1://1을 선택했을때
			printf("Search : ");
			scanf("%d", &num);
			result = addNodeList(list, num);
			if (result == false) {
				printf("My List has %d.\n", num);
				showList(list);
				break;
			}
			printf("My List does not have %d.\n", num);
			removeList(list, num);
			showList(list);
			break;
		case 2://2을 선택했을때
			printf("Out : ");
			scanf("%d", &num);
			result = removeList(list, num);
			if (result == true) {
				printf("%d was removed.\n", num);
				showList(list);
				break;
			}
			printf("My List does not have %d.\n", num);
			showList(list);
			break;
		case 3://3을 선택했을때
			destroyList(list);
			return 0;
		default:
			break;
		}

	}



}

void showList(List* pList) {
	int result;
	int count = 0;
	Element* temp = (Element*)malloc(sizeof(Element));
	printf("The current staus of List : ");
	while (result = traverseList(pList, 1, temp)) {
		printf("%d", *temp);
		count++;
		if (count < pList->count) printf(", ");
	}
	free(temp);
	printf("\n\n\n");
}