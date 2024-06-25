#include "header.h"

int main(){
  int arr1[] = {12,5,17,9,7,3,10,20,2};
  int n1 = 8;
  recurMergeSort(arr1, 0, 7);

  for(int i = 0; i<n1; i++)
      printf("%d,", arr1[i]);
  printf("\n");

  return 0;
}
