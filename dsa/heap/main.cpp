#include "header.h"

int main(){
  int arr[] = {0,10,20,30,25,5,40,35};
  Heap h(arr, 8);
  int a[] = {0,10,20,30,25,5,40,35};
  Heap h2;
  h2.heapify(a,8);
  for(int i = 1; i<8; i++)
    cout<<arr[i]<<", ";
  cout<<endl;
  for(int i = 1; i<8; i++)
    cout<<a[i]<<", ";
  cout<<endl;
  return 0;
}
