#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int list[], int n)
{
	int i = 0, j = 0;
	int smallest = 0;
	for (i = 0; i < n - 1; i++) {
		smallest = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[smallest])
				smallest = j;
		// Smallest selected: exchange with current
		swap(&list[i], &list[smallest]);
	}
} // selectionSort

void insertionSort(int list[], int n)
{
	int i = 0, j = 0;
	int hold = 0;
	for (i = 1; i < n; i++) {
		hold = list[i];
		for (j = i; j > 0 && hold < list[j - 1]; j--)
			list[j] = list[j - 1];
		list[j] = hold;
	}
} // insertionSort

void bubbleSort(int list[], int n)
{
	int i = 0, j = 0;
	int sorted = false;
	for (i = 0; i < n && !sorted; i++) {
		for (j = n - 1, sorted = true; j > i; j--) {
			if (list[j] < list[j - 1]) {
				sorted = false; // Any exchange means list is not sorted
				swap(&list[j], &list[j - 1]);
			}
		}
	}
} // bubbleSort

void quicksort(int list[], int left, int right)
{
	int pivot = 0, i = 0, j = 0;
	// It is assumed that list[left].key <= list[right+1].key
	if (left < right) {
		i = left; j = right + 1;
		pivot = list[left];
		do {
			do
				i++;
			while (list[i] < pivot);
			do
				j--;
			while (list[j] > pivot);
			if (i < j)
				swap(&list[i], &list[j]);
		} while (i < j);
	
	swap(&list[left], &list[j]);
	quicksort(list, left, j - 1);
	quicksort(list, j + 1, right);
	}
}

void Merge(int list[], int sorted[], int i, int m, int n)
{
	int j, k, t, low = i;
	j = m + 1;
	k = i;
	while (i <= m && j <= n) {
		if (list[i] < list[j]){
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}
	if (i > m) { // All elements in left list are copied
		for (t = j; t <= n; t++) // copy remained elements in right list
			sorted[k + t - j] = list[t];
	}
	else { // There are remained elements in left list
		for (t = i; t <= m; t++)// copy remained elements in left list
			sorted[k + t - i] = list[t];
	}
	for (int a = low; a <= n; a++)
		list[a] = sorted[a];
}

void MergeSort(int list[], int sorted[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(list, sorted, low, mid);
		MergeSort(list, sorted, mid + 1, high);
		Merge(list, sorted, low, mid, high); // in place
	}
}

void Sort(int list[], int sizeof_list) {
	int* sorted_list = NULL;
	printf("\n\nChoose a sorting method to use(Selection : 0, Insertion : 1, Bubble : 2, Quick : 3, Merge : 4 ) : ");
	int select;
	scanf("%d", &select);
	switch (select) {
	case 0:
		selectionSort(list, sizeof_list);
		break;
	case 1:
		insertionSort(list, sizeof_list);
		break;
	case 2:
		bubbleSort(list, sizeof_list);
		break;
	case 3:
		quicksort(list, 0, sizeof_list-1);
		break;
	case 4:
		sorted_list = (int*)calloc(sizeof_list,sizeof(int));
		MergeSort(list, sorted_list, 0, sizeof_list-1);
		
		for (int i = 0; i < sizeof_list; i++) {
			list[i] = sorted_list[i];
		}
		free(sorted_list);
		break;
	default:
		Sort(list, sizeof_list);
		return;
	}
	printf("\n");
	printf("The numbers sorted : ");
	for (int i = 0; i < sizeof_list; i++) {
		printf("%d", list[i]);
		if (i != sizeof_list - 1) {
			printf(", ");
		}
		else {
			printf("\n");
		}

	}
	return;
}