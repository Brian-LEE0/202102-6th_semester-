#include "Sort.h"

int main(){
    char temp[100];
    int count = 0;
    int list[100];
    printf("Input file name : ");
    scanf(" %[^\n]s",temp);
    printf("%s", temp);
    FILE* fin = fopen(temp,"r");
    if (!fin)
        return 0;

    while(fin!='\0'){
        list[count++] = atoi(fgets(temp,100,fin));
    }

}
