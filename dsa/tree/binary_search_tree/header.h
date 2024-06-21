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

class Stack{
    private:
        node* head;
    public:
        Stack(){head=nullptr;}
        void push(tnode* t);
        tnode* pop();
        bool isEmpty();
        tnode* get_top(){return head->ele;}
};

class Tree{
  private:
    tnode *root;
  public:
    Tree(){root = new tnode; root->left = root->right = nullptr;}
    Tree(int* arr, int n);
    tnode* get_root() {return root;}
    int height(tnode* p);
    tnode* search(int key);
    tnode* rSearch(tnode *p, int key);
    void insert(int value);
    tnode* rInsert(tnode* p,int value);
    void inorder(tnode* p);
    tnode* inorderPredecessor(tnode* p);
    tnode* inorderSuccessor(tnode* p);
    tnode* deleteNode(tnode* p, int key);
    void createFromPre(int *arr, int n);
    void createFromPost(int *arr, int n);
};
