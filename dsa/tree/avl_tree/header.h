#include<iostream>
using namespace std;

typedef struct Tnode {
  struct Tnode* right;
  int data;
  int height;
  struct Tnode* left;
} tnode;

class Tree{
  private:
    tnode* root;
  public:
    Tree(){root = nullptr;}
    tnode* get_root(){return root;}
    void inorder();
    tnode* insert(tnode* p, int value);
    void deleteNode(int key);
    tnode* search(int key);
    int nodeHeight(tnode* p);
    int balanceFactor(tnode* p);
    tnode* LLrotation(tnode* p);
    tnode* LRrotation(tnode* p);
    tnode* RRrotation(tnode* p);
    tnode* RLrotation(tnode* p);
    tnode* inorderSuc(tnode* p);
    tnode* inorderPre(tnode* p);
    tnode* rDelete(tnode* p, int key);
};
