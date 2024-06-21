#include "header.h"

int main(){
  int arr[] = {3,8,9,7,6,13,11,16,18,17,15,10};
  Tree tr;
  tr.createFromPost(arr, 12);
  tr.inorder(tr.get_root());
  cout<<endl;
  return 0;
}
