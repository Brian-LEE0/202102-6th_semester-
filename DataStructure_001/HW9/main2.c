#include "Sort.h"

int main(){
    char temp[100], * result;
    int count = 0;
    int list[10000];
    printf("Input file name : ");
    scanf(" %[^\n]s",temp);
    FILE* fin = fopen(temp, "r");
    if (!fin) {
        printf("Error : Cannot match file at this location\n");
        return -1;
    }

    while (result = fgets(temp, 100, fin) != NULL) {
        list[count++] = atoi(temp);
    }
    fclose(fin);
    Sort(list, count);
    return 0;
}
