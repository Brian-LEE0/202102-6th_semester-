#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char temp1[100], temp2[100];
	int num[20];
	char *ptr;
	int buf;
	int i = 0, j = 10, k = 0, l = 0, m = 0;
	int temp;

	printf("Input :\n");
	scanf("%[^\n]s", temp1);
	scanf(" %[^\n]s", temp2);

	ptr = strtok(temp1, ",");

	while (ptr != NULL)
	{
		num[i] = atoi(ptr);
		ptr = strtok(NULL, ",");
		if (i > 0)
		{
			if (num[i - 1] >= num[i])
			{
				k += 1;
			}
		}
		i += 1;
	}

	ptr = strtok(temp2, ",");

	while (ptr != NULL)
	{
		num[j] = atoi(ptr);
		ptr = strtok(NULL, ",");
		if (j > 10)
		{
			if (num[j - 1] >= num[j])
			{
				l += 1;
			}
		}
		j += 1;
	}

	if ((i != 10) || (j != 20))
	{
		printf("ERROR : You should input number of integers 2 * 10 in total.\n");
		return -1;
	}

	if ((k != 0) || (l != 0))
	{
		printf("ERROR : The input numbers are not in ascending order\n");
		return -2;
	}

	for (int a = 0; a < j; a++)
	{
		for (int b = a; b < j; b++)
		{
			if (num[a] > num[b])
			{
				temp = num[a];
				num[a] = num[b];
				num[b] = temp;
			}
		}
	}

	printf("Output :\n");
	buf = num[0];
	for (int a = 0; a < j; a++)
	{
		if (a > 0)
		{
			if (buf != num[a])
			{
				printf("%d", num[a]);
				if (a < j - 1)
				{
					printf(", ");
				}
				else
				{
					printf("\n");
				}
				buf = num[a];
			}
		}
		else
		{
			printf("%d", num[a]);
			printf(", ");
		}
	}
	return 0;
}
