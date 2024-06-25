#include "header.h"

int main(){
  int arr1[] = {12,5,7,9,7,3,10,20,2};
  int n1 = 9;
  binSort(arr1, 9);

  for(int i = 0; i<n1; i++)
      printf("%d,", arr1[i]);
  printf("\n");

  return 0;
}
