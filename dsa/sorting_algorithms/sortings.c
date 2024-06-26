#include "header.h"
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*
 compares two adjacent elements and swaps them if the first is larger than the
 sencond. after one pass, the largest element is found at the last index of the
 array.
*/
void bubbleSort(int *arr, int n) {
  // flag makes the algorithm adaptive, if there is no swap in a complete
  // iteration, it means that the array is sorted and the algorithm stops.
  int flag = 0;
  for (int i = 0; i < n - 1; i++) {
    flag = 0;
    // hte inner loop runs only n-1-i times because after each outer loop the
    // last i elements are sorted. therefore only the remaining elements are
    // being compared.
    for (int j = 0; j < n - 1 - i; j++) {
      // comparting the adjacent elements and swapping them if condition
      // satisfies and change the flag to 1.
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        flag = 1;
      }
    }
    // checking if the flag is still 0 after a complete iteration meaning there
    // was no swapping and then stopping the algorithm.
    if (flag == 0)
      break;
  }
}

//======================================================================================================================================

/*
  keeps a pointer i, the part of the array left to the pointer i is sorted and
  the part right to it is not. the algorithm inserts one element from right side
  to the left side and keeps shifting it till the element before it is larger
  than the element itself suppose the array is [5,3,2,12,8], initially the
  pointer is at the first element, this means that the array of a single element
  5 is sorted, then the next element that is 3 is inserted to the sorted part.
  Since 3 is smaller than 5, therefore the after the insertion of 3, the array
  looks like this [5,3,2,12,8], then the element 2 is inserted and the array
  becomes [2,3,5,12,8], then 12 is inserted and there are no swaps as 12 is
  larger than 5, then lastly 8 is inserted and there is just one swap and the
  array becomes [2,3,5,8,12].... SORTED!!!
*/
void insertionSort(int *arr, int n) {
  int i, j, x;
  for (i = 1; i < n; i++) {
    j = i - 1;
    // the inserted element is stored in a variable and then written at the
    // index to which it should be inserted.
    x = arr[i];
    // the elements greater than the element being inserted are shifted one
    // place to the right, and stops if a number smaller than the inserted
    // element is found or the first index is reached.
    while (j > -1 && arr[j] > x) {
      arr[j + 1] = arr[j];
      j--;
    }
    // finally inserting the element to its index.
    arr[j + 1] = x;
  }
}

//======================================================================================================================================

/*
  This algorithm chooses an index, and then the element that should be in that
  particular index is put in the index. The choosen index starts at 0 and then
  moves to n, that is the size of the array. Suppose the array is [5,3,2,12,8],
  there are three pointers i,j,k. i points at the choosen index. j is for
  finding the minimum element in the unsorted array, k is for pointing at that
  minimum element. according to the array, i=j=k=0. now j moves forward and
  points to 3, since 3 is smaller than the element to which k is pointing.
  therefore now k points at 3 and j moves forward, now since 2 is smaller than
  the element to which k is pointing, k moves to 2. Now j moves forward, since
  12 is larger than 2, therefore j moves forward. Since 8 is larger than 2,
  therefore j moves forward. Now j reaches the end of the array and now, the
  elements at i and k are swapped, now we have the minimum element at the first
  index. Now after one whole loop, i moves forward and k and j move where i is
  pointing and the process is repeated.
*/
void selectionSort(int *arr, int n) {
  int i, j, k;
  for (i = 0; i < n - 1; i++) {
    // j and k point where i is pointing and the loop runs till j reaches the
    // end of array.
    for (j = k = i; j <= n - 1; j++) {
      // if the element at j is smaller than the element at k, k points where j
      // is pointing.
      if (arr[j] < arr[k]) {
        k = j;
      }
    }
    // at the end of the inner loop, the elements at i and k are swapped.
    swap(&arr[i], &arr[k]);
  }
}

//=======================================================================================================================================

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
    if (i < j)
      swap(&arr[j], &arr[i]);
  } while (i < j);
  swap(&arr[l], &arr[j]);
  return j;
}

void quickSort(int *arr, int l, int h) {
  int j;
  if (l < h) {
    j = partition(arr, l, h);
    quickSort(arr, l, j);
    quickSort(arr, j + 1, h);
  }
}

//=======================================================================================================================================

int *mergeSortedArrays(int *a, int *b, int n1, int n2) {
  int *final = (int *)malloc(sizeof(int) * (n1 + n2));
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (a[i] <= b[j])
      final[k++] = a[i++];
    else
      final[k++] = b[j++];
  }
  while (i < n1)
    final[k++] = a[i++];
  while (j < n2)
    final[k++] = b[j++];
  return final;
}

void merge(int *a, int l, int mid, int h) {
  int b[h + 1];
  int i = l, j = mid + 1;
  int k = l;
  printf("l: %d, h: %d, mid: %d\n", l, h, mid);
  while (i < mid + 1 && j < h + 1) {
    if (a[i] <= a[j])
      b[k++] = a[i++];
    else
      b[k++] = a[j++];
  }
  while (i < mid + 1)
    b[k++] = a[i++];
  while (j < h + 1)
    b[k++] = a[j++];
  for (int m = l; m < h + 1; m++)
    a[m] = b[m];
}

void iterMergeSort(int *arr, int n) {
  int p, mid, i, l, h;
  for (p = 2; p <= n; p = p * 2) {
    for (i = 0; i + p - 1 < n; i = i + p) {
      l = i;
      h = i + p - 1;
      mid = (h + l) / 2;
      merge(arr, l, mid, h);
    }
  }
  if (p / 2 < n)
    merge(arr, 0, p / 2, n - 1);
}

void recurMergeSort(int *arr, int l, int h) {
  if (l < h) {
    int mid = (h + l) / 2;
    recurMergeSort(arr, l, mid);
    recurMergeSort(arr, mid + 1, h);
    merge(arr, l, mid, h);
  }
}

int findMax(int *arr, int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

void countSort(int *arr, int n) {
  int max = findMax(arr, n);
  int b[max + 1];
  int i = 0;
  while (i < max + 1)
    b[i++] = 0;

  for (int j = 0; j < n; j++)
    b[arr[j]]++;

  int j = 0;
  i = 0;
  while (i < max + 1) {
    if (b[i] > 0) {
      arr[j++] = i;
      b[i]--;
    } else {
      i++;
    }
  }
}

node *insert(node *head, int data) {
  node *t = (node *)malloc(sizeof(node));
  t->data = data;
  t->next = NULL;
  node *p = head;
  if (!p)
    head = t;
  else {
    while (p->next)
      p = p->next;
    p->next = t;
  }
  return head;
}

node* deleteNode(node *head) {
  node *p = head;
  head = head->next;
  free(p);
  return head;
}

void binSort(int *arr, int n) {
  int max = findMax(arr, n);
  int size = sizeof(node *) * (max + 1);
  node **bins = (node **)malloc(size);
  int i;
  for (i = 0; i < max + 1; i++)
    bins[i] = NULL;

  int j;
  for (j = 0; j < n; j++) {
    bins[arr[j]] = insert(bins[arr[j]], arr[j]);
  }
  i = j = 0;
  while (i < max + 1) {
    while (bins[i] != NULL) {
      arr[j++] = i;
      bins[i] = deleteNode(bins[i]);
    }
    i++;
  }
}

void radixSort(int *arr, int n) {
  node **bins;
  bins = (node **)malloc(sizeof(node *) * 10);
  int max = findMax(arr, n);
  int divisor = 1;
  while (divisor <= max) {
    int i, j;
    for(j = 0; j < 10; j++)
      bins[j] = NULL;
    for (i = 0; i < n; i++) {
      int bin_number = (arr[i] / divisor) % 10;
      bins[bin_number] = insert(bins[bin_number], arr[i]);
    }
    i = j = 0;
    while (j < 10) {
      while (bins[j] != NULL) {
        arr[i++] = bins[j]->data;
        bins[j] = deleteNode(bins[j]);
      }
      j++;
    }
    divisor *= 10;
  }
}
