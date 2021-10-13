
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    typedef struct {
        char name[50]; // 이름
        int age;
        char sex;
        char* namep; // 성을 가리키는 포인터
    } student;
    //programming going on
    // 아래에 코드를 채워넣으세요.

	char* temp;
    int a = 0;
    student* std = (student*)malloc(sizeof(student) * (a + 1));
    
  

    while (1) {
        printf("Provide your personal information:\n");
        printf("➢ Name : ");
        scanf(" %[^\n]", std[a].name);
        if (!strcmp(std[a].name, "stop")) {
            free(std);
            break;
        }

        printf("➢ Age: ");
        scanf(" %d", &std[a].age);

        printf("➢ Sex (M/F): ");
        scanf(" %c", &std[a].sex);

		strtok(std[a].name," ");
		std[a].namep = strtok(NULL," ");
		
		
		printf("\n\nYour name is %s %s, your age is %d, your sex is %c\n\n\n",std[a].namep, std[a].name,std[a].age,std[a].sex);
		a++;
		std = (student*)realloc(std, sizeof(student)*(a+1));


    }

    return 0;
}