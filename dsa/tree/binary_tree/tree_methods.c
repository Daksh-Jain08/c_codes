#include<stdio.h>
#include<stdlib.h>
#include"header.h"

tnode * declare_tree(){
    tnode *root = (tnode *)malloc(sizeof(tnode));
    root->left=root->right=NULL;
    
    return root;
}

void create_tree(tnode *root){
    queue q;
    int x;
    tnode *p,*t;
    create_queue(&q);
    printf("Enter the root value: ");
    scanf("%d", &root->data);
    enqueue(&q, root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter the data in left child of %d, if left child does not exist, input '-1': ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (tnode *)malloc(sizeof(tnode));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&q, t);
        }
        
        printf("Enter the data in right child of %d, if right child does not exist, input '-1': ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (tnode *)malloc(sizeof(tnode));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q, t);
        }

    }
}

void preorder(tnode *p){
    if(p){
        printf("%d,", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(tnode *p){
    if(p){
        inorder(p->left);
        printf("%d,", p->data);
        inorder(p->right);
    }
}

void postorder(tnode *p){
    if(p){
        postorder(p->left);
        postorder(p->right);
        printf("%d,", p->data);
    }
}