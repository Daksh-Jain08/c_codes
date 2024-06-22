#include "header.h"

int main(){
  int arr[] = {2,12,5,7,3,10,20,17};
  int n = 8;
  insertionSort(arr, n);
  for(int i = 0; i<n; i++)
      printf("%d,", arr[i]);
  printf("\n");
  return 0;
}
