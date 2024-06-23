#include "header.h"
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int *arr, int n) {
  int flag = 0;
  for (int i = 0; i < n - 1; i++) {
    flag = 0;
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
}

void insertionSort(int *arr, int n) {
  int i, j, x;
  for (i = 1; i < n; i++) {
    j = i - 1;
    x = arr[i];
    while (j > -1 && arr[j] > x) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = x;
  }
}

void selectionSort(int *arr, int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    for (j = k = i; j < n - 1; j++) {
      if (arr[j] < arr[k]) {
        k = j;
      }
    }
    swap(&arr[i], &arr[k]);
  }
}

int partition(int *arr, int l, int h) {
  int pivot = arr[l];
  int i = l, j = h;
  do {
    do {
      i++;
    } while (arr[i] <= pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    printf("i: %d, j: %d\n", i,j);
    if (i < j){
      printf("Done, ");
      swap(&arr[j], &arr[i]);
    }
  } while (i < j);
  swap(&arr[l], &arr[j]);
  return j;
}

void quickSort(int *arr, int l, int h) {
  int j;
  if(l<h){
    printf("Entered\n");
    j = partition(arr, l, h);
    quickSort(arr, l, j);
    quickSort(arr, j+1, h);
  }
}
