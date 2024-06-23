#include "header.h"
#include<limits.h>
int main(){
  int arr[] = {5,12,17,7,3,10,20,2,INT_MAX};
  int n = 8;
  quickSort(arr, 0, n);
  for(int i = 0; i<n; i++)
      printf("%d,", arr[i]);
  printf("\n");
  return 0;
}
