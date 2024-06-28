#include "header.h"

void insertNode(node **head, int data) {
  //creating new node in heap and inserting new data in it.
  node *t = new node;
  t->data = data;
  //if head is null, then making t as the head.
  if (!*head) {
    t->next = nullptr;
    *head = t;
    return;
  } else {
    node *p = *head;
    //if the data in head is greater than the inserted data, then making the new node as head.
    if(p->data>data){
      t->next = p;
      *head = t;
      return;
    }
    //finding the node before the appropriate position of the new node and inserting the new node after it.
    while (p->next && p->next->data < data)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

ChainHash::ChainHash() {
  for (int i = 0; i < 10; i++)
    root[i] = nullptr;
}

int ChainHash::getHash(int data) const { return data % 10; }

void ChainHash::insertEle(int data) {
  int index = getHash(data);
  insertNode(&root[index], data);
}

node *search(node *head, int data) {
  node *p = head;
  while (p && p->data <= data) {
    if (p->data == data)
      return p;
    p = p->next;
  }
  return nullptr;
}

node *ChainHash::searchEle(int data) const {
  int index = getHash(data);
  node *p = search(root[index], data);
  return p;
}

bool ChainHash::deleteEle(int data) {
  //if the element is not in the Hash Table then returning false.
  if (!searchEle(data))
    return false;

  int index = getHash(data);
  node *p = root[index];
  if(p->data==data){
    root[index] = p->next;
    free(p);
    return true;
  }
  //finding the node just before the node to be deleted and making the required changes.
  while (p->next && p->next->data != data)
    p = p->next;
  node *t = p->next;
  p->next = t->next;
  free(t);
  return true;
}

ostream &operator<<(ostream &stream, ChainHash &ch) {
  node **root = ch.getRoot();
  for (int i = 0; i < 10; i++) {
    node *p = root[i];
    stream << i << ": ";
    while (p) {
      stream << p->data << ", ";
      p = p->next;
    }
    stream << endl;
  }
  return stream;
}
