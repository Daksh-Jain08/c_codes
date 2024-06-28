#include "header.h"

int main() {
  ChainHash ch;
  ch.insertEle(4);
  ch.insertEle(76);
  ch.insertEle(3);
  ch.insertEle(28);
  ch.insertEle(34);
  ch.insertEle(6);
  cout<<ch;

  if(ch.deleteEle(24))
    cout<<"24 has been deleted"<<endl;
  else
    cout<<"24 is not in the Table"<<endl;

  cout<<ch;
}
