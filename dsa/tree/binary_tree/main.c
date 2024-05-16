#include<stdio.h>
#include"header.h"

int main(){
    tnode *root = declare_tree();
    create_tree(root);
    preorder(root);
    return 0;
}