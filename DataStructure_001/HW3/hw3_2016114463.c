#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    typedef struct
    {
        int no;
        char name[50];
        int age;
        int math;
        int english;
        int history;
    } student;

    int menu;
    char file_name[100];
    int n;
    char buff[100];
    int sort_num;
    int exitOuterLoop;
    FILE* list;
    student* std = NULL;
    student temp;

    while (1)
    {
        printf("============================\n");
        printf("1) Insert\n");
        printf("2) Sort\n");
        printf("3) Quit\n");
        printf("Select a menu : ");

        scanf("%d", &menu);

        switch (menu)
        {
        case 1: // case of Insert
            printf("File name : ");
            scanf(" %[^\n]s", file_name);
            list = fopen(file_name, "r");
            if (list == NULL)
            {
                printf("There is no file to read\n");
                printf("\n============================\n");
                break;
            }

            n = 0;
            std = (student*)malloc(sizeof(student) * (n));
            exitOuterLoop = 0;

            while (1)
            {
                if (fgets(buff, 100, list) != NULL)
                {

                    std = (student*)realloc(std, sizeof(student) * (n + 1));

                    std[n].no = n + 1;
                    strcpy(std[n].name, strtok(buff, " "));
                    std[n].age = atoi(strtok(NULL, " "));
                    if (std[n].age < 0)
                    {
                        printf("Result : The age cannot be a negative number. Program terminates.\n");
                        printf("============================\n");
                        exitOuterLoop = 1;
                        break;
                    }
                    std[n].math = atoi(strtok(NULL, " "));
                    if (std[n].math < 0)
                    {
                        printf("Result : The math cannot be a negative number. Program terminates.\n");
                        printf("============================\n");
                        exitOuterLoop = 1;
                        break;
                    }
                    std[n].english = atoi(strtok(NULL, " "));
                    if (std[n].english < 0)
                    {
                        printf("Result : The english cannot be a negative number. Program terminates.\n");
                        printf("============================\n");
                        exitOuterLoop = 1;
                        break;
                    }
                    std[n].history = atoi(strtok(NULL, " "));
                    if (std[n].history < 0)
                    {
                        printf("Result : The history cannot be a negative number. Program terminates.\n");
                        printf("============================\n");
                        exitOuterLoop = 1;
                        break;
                    }
                    n++;
                }
                else
                    break;
            }
            if (exitOuterLoop == 1)
                break;

            printf("no Name Age Math English History\n");

            for (int i = 0; i < n; i++)
            {
                printf("%d ", std[i].no);
                printf("%s ", std[i].name);
                printf("%d ", std[i].age);
                printf("%d ", std[i].math);
                printf("%d ", std[i].english);
                printf("%d\n", std[i].history);
            }
            break;

        case 2: // case of Sort
            if (std == NULL)
            {
                printf("Result : There is no data to be sorted. Program terminates.\n");
                printf("============================\n");
                break;
            }
            printf("1) Name\n");
            printf("2) Age\n");
            printf("3) Math\n");
            printf("4) English\n");
            printf("5) History\n");
            printf("Choose the field to sort by : ");

            scanf("%d", &sort_num);

            switch (sort_num)
            {
            case 1: //Name
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (strcmp(std[i].name, std[j].name) < 0)
                        {
                            temp = std[i];
                            std[i] = std[j];
                            std[j] = temp;
                        }
                    }
                }

                printf("no Name Age Math English History\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", i + 1);
                    printf("%s ", std[i].name);
                    printf("%d ", std[i].age);
                    printf("%d ", std[i].math);
                    printf("%d ", std[i].english);
                    printf("%d\n", std[i].history);
                }
                break;
            case 2: //Age
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (std[i].age < std[j].age)
                        {
                            temp = std[i];
                            std[i] = std[j];
                            std[j] = temp;
                        }
                    }
                }
                printf("no Age Name Math English History\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", i + 1);
                    printf("%d ", std[i].age);
                    printf("%s ", std[i].name);
                    printf("%d ", std[i].math);
                    printf("%d ", std[i].english);
                    printf("%d\n", std[i].history);
                }
                break;
            case 3: //math
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (std[i].math < std[j].math)
                        {
                            temp = std[i];
                            std[i] = std[j];
                            std[j] = temp;
                        }
                    }
                }

                printf("no Math Name Age English History\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", i + 1);
                    printf("%d ", std[i].math);
                    printf("%s ", std[i].name);
                    printf("%d ", std[i].age);
                    printf("%d ", std[i].english);
                    printf("%d\n", std[i].history);
                }
                break;
            case 4: //english
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (std[i].english < std[j].english)
                        {
                            temp = std[i];
                            std[i] = std[j];
                            std[j] = temp;
                        }
                    }
                }

                printf("no English Name Age Math History\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", i + 1);
                    printf("%d ", std[i].english);
                    printf("%s ", std[i].name);
                    printf("%d ", std[i].age);
                    printf("%d ", std[i].math);
                    printf("%d\n", std[i].history);
                }
                break;
            case 5: //history
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (std[i].history < std[j].history)
                        {
                            temp = std[i];
                            std[i] = std[j];
                            std[j] = temp;
                        }
                    }
                }

                printf("no History Name Age Math English\n");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", i + 1);
                    printf("%d ", std[i].history);
                    printf("%s ", std[i].name);
                    printf("%d ", std[i].age);
                    printf("%d ", std[i].math);
                    printf("%d\n", std[i].english);
                }
                break;
            }
            break;

        case 3:
            printf("\n============================\n");
            free(std);
            return 0;
        }
    }
}