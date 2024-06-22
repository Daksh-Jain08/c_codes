#include "header.h"

Heap::Heap(int *a, int n) {
  arr = a;
  for (int i = 2; i < n; i++)
    insert(i);
  cout<<"done";
}

void Heap::insert(int index) {
  int i = index, temp = arr[index], times=0;
  while (i > 1 && temp > arr[i / 2]) {
    arr[i] = arr[i / 2];
    i = i / 2;
    times++;
  }
  cout<<times<<endl;
  arr[i] = temp;
}

int Heap::deleteEle(int index) {
  int i, j, x = arr[index], temp;
  int val = arr[1];
  arr[1] = arr[index];
  arr[index] = val;
  i = 1;
  j = 2;

  while (j < index-1) {
    if (arr[j] < arr[j + 1])
      j++;
    if (arr[i] < arr[j]) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i = j;
      j = j * 2;
    } else {
      break;
    }
  }
  return val;
}

void Heap::heapSort(int *a, int n) {
  for (int i = n - 1; i > 0; i--)
    a[i] = deleteEle(i);
}

void Heap::heapReorder(int *a, int index, int n){
  int temp, j=index*2, i=index, times=0;
  while(j<n-1){
    if(a[j]<a[j+1])
      j++;
    if(a[i]<a[j]){
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i = j;
      j = 2*j;
      times++;
    }
    else break;
  }
  cout<<times<<endl;
}

void Heap::heapify(int *a, int n){
  int i,j,temp;
  if(!n%2)
    i = n/2;
  else
    i = n/2-1;
  j = i*2;
  while(i>0){
    heapReorder(a,i,n);
    i--;
  }
}










