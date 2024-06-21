#include "header.h"

int main(){
  Tree tr;
  tr.insert(tr.get_root(),40);
  tr.insert(tr.get_root(),50);
  tr.insert(tr.get_root(),10);
  tr.insert(tr.get_root(),11);
  tr.insert(tr.get_root(),7);
  cout<<tr.get_root()->data<<endl;
  //cout<<tr.balanceFactor(tr.get_root())<<endl;
  tr.insert(tr.get_root(),13);
  tr.insert(tr.get_root(),70);
  //cout<<tr.balanceFactor(tr.get_root())<<endl;
  cout<<tr.get_root()->data<<endl;
  tr.rDelete(tr.get_root(),7);
  cout<<tr.get_root()->data<<endl;
  //cout<<tr.get_root()->right->left->data<<endl;
}
