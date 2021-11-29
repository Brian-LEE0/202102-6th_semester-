//#include "Search.h"
#include "Hash_Search.h"

int compare(void* argu1, void* argu2);

int main(int argc, char* argv[]) {
	SPACE* space = CreateSpace(10000, compare);
	if (!space) {
		return -1;
	}

	for (int i = 0; i < 300; i++) {
		SaveData(space, i * 32, i);
	}
	if (Search(space,9220)) {
		printf("Good\n\n");
	}
	else {
		printf("Fail\n\n");
	}
}

int compare(void* argu1, void* argu2) {
	return (*(element*)argu1) - (*(element*)argu2);
}