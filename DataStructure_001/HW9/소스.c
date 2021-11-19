#include "Search.h"

int main(int argc, char* argv[]) {
	SPACE* space = CreateSpace(10000);
	if (!space) {
		printf("?");
		return 0;
	}

	for (int i = 0; i < 3000; i++) {
		SaveData(space, i * 2, i);
	}
	if (BinarySearch(space,601)) {
		printf("Good\n\n");
	}
	else {
		printf("Fail\n\n");
	}
}
