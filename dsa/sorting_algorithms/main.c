#include "header.h"

int main(){
  int arr1[] = {5,7,9,7,3,10,20,2};
  int n1 = 8;
  shellSort(arr1, n1);

  for(int i = 0; i<n1; i++)
      printf("%d,", arr1[i]);
  printf("\n");

  return 0;
}
