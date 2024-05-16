#include<iostream>

using namespace std;

typedef struct Tnode {
    Tnode *left;
    int data;
    Tnode *right;
} tnode;

typedef struct Node{  
    tnode *ele;
    struct Node *next;
} node;

class Queue{
    private:
        node *front;
        node *rear;
    public:
        Queue(){front=rear=nullptr;}
        void enqueue(tnode *ele);
        tnode * dequeue();
        bool isEmpty();
};

class Tree{
    private:
        tnode *root;
    public:
        Tree(){root = new tnode; root->left = root->right = nullptr;}
        void create();
        void preorder(tnode *p);
        void inorder(tnode *p);
        void postorder(tnode *p);
        tnode * get_root(){return root;}
};