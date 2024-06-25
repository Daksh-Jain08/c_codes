#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);
int partition(int *arr, int l, int h);
void quickSort(int *arr, int l, int h);
int *mergeSortedArrays(int *a, int *b, int n1, int n2);
void iterMergeSort(int *arr, int n);
void recurMergeSort(int *arr, int h, int l);
void merge(int *a, int h, int l, int mid);
