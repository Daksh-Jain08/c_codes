#include "header.h"

void Queue::enqueue(int element){
  node *t = new node;
  if(!t){
    cout<<"Queue Overflow!!"<<endl;
    return;
  }
  t->data = element;
  t->next = nullptr;
  if(!front){
    front = rear = t;
    return;
  }
  rear->next = t;
  rear = t;
}

int Queue::dequeue(){
  if(!front){
    cout<<"Queue Underflow"<<endl;
    return -1;
  }
  node* p = front;
  int x = front->data;
  front = front->next;
  free(p);
  return x;
}

bool Queue::isEmpty(){
  return front==nullptr?true:false;
}
