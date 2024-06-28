#include<iostream>

using namespace std;

typedef struct Node {
  int data;
  struct Node *next;
} node;

void insertNode(node **head, int data);
node* search(node *head, int data);

class ChainHash{
  private:
    node *root[10];
  public:
    ChainHash();
    node** getRoot(){return root;}
    int getHash(int data) const;
    void insertEle(int data);
    node* searchEle(int key) const;
    bool deleteEle(int key);
};

ostream& operator<<(ostream& stream, ChainHash& ch);
