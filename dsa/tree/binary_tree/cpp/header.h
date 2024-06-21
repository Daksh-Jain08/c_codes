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
        node* getFront(){return front;}
        node* getRear(){return rear;}
        void enqueue(tnode *ele);
        tnode * dequeue();
        bool isEmpty();
};

class Stack{
    private:
        node* head;
    public:
        Stack(){head=nullptr;}
        void push(tnode* t);
        tnode* pop();
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
        void iterpreorder();
        void iterinorder();
        void iterpostorder();
        void levelorder();
        int count_nodes(tnode *p);
        int height(tnode *p);
        int count_leaf_nodes(tnode *p);
        int count_degree_two_nodes(tnode *p);
};
