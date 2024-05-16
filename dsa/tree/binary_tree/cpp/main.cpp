#include<iostream>
#include"header.h"

using namespace std;

int main(){
    Tree tr = Tree();
    tr.create();

    tr.preorder(tr.get_root());
    return 0;
}