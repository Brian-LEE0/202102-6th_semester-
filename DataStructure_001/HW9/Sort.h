#pragma once
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
	// It is assumed that list[left].key <= llist[right+1].key
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
	}
	swap(&list[left], &list[j]);
	quicksort(list, left, j - 1);
	quicksort(list, j + 1, right);
}

void Merge(int list[], int sorted[], int i, int m, int n)
{
	int j, k, t;
	j = m + 1;
	k = i;
	while (i <= m && j <= n) {
		if (list[i] < list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > m) { // All elements in left list are copied
		for (t = j; t <= n; t++) // copy remained elements in right list
			sorted[k + t - j] = list[t];
	}
	else { // There are remained elements in left list
		for (t = i; t <= m; t++)// copy remained elements in left list
			sorted[k + t - i] = list[t];
	}
}

void MergeSort(int list[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(list, low, mid);
		MergeSort(list, mid + 1, high);
		Merge(list, list, low, mid, high); // in place
	}
}

