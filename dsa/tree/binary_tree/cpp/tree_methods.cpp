#include<stdio.h>
#include"header.h"

void Tree::create(){
    Queue q = Queue();
    int x;
    tnode *p, *t;

    cout<<"Enter the value of root node: ";
    cin>>root->data;

    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter the value for left child of " << p->data << ", if left child doesn't exist, input '-1': ";
        cin>>x;
        if(x!=-1){
            t = new tnode;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;

            q.enqueue(t);
        }

        cout<<"Enter the value for right child of " << p->data << ", if right child doesn't exist, input '-1': ";
        cin>>x;
        if(x!=-1){
            t = new tnode;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;

            q.enqueue(t);
        }
    }
}

void Tree::preorder(tnode *p){
    if(p){
        cout<<p->data<<", ";
        preorder(p->left);
        preorder(p->right);
    }
}

void Tree::inorder(tnode *p){
    if(p){
        inorder(p->left);
        cout<<p->data<<", ";
        inorder(p->right);
    }
}

void Tree::postorder(tnode *p){
    if(p){
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<", ";
    }
}