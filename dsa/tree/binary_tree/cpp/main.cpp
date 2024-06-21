#include<iostream>
#include"header.h"

using namespace std;

int main(){
    Tree tr = Tree();
    tr.create();

    tr.preorder(tr.get_root());
    cout<<endl;
    cout<<tr.height(tr.get_root())<<endl;
    return 0;
}
