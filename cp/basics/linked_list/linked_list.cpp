#include <iostream>

using namespace std;

template <typename T> class Node {
  T data;
  Node<T> *next;

public:
  Node(T data) {
    this->data = data;
    next = NULL;
  }

  T getData() { return data; }
  void setData(T data) { this->data = data; }
  Node<T> *getNext() { return next; }
  void setNext(Node<T> *next) { this->next = next; }
};

template <typename T> void insertAtHead(Node<T> *&head, T data) {
  Node<T> *newNode = new Node<T>(data);
  newNode->setNext(head);
  head = newNode;
}

template <typename T> void insertAtIndex(Node<T> *&head, T data, int index) {
  if (index == 0) {
    insertAtHead(head, data);
    return;
  }
  Node<T> *temp = head;
  for (int i = 0; i < index - 1 and temp != NULL; i++) {
    temp = temp->getNext();
  }
  Node<T> *newNode = new Node<T>(data);
  newNode->setNext(temp->getNext());
  temp->setNext(newNode);
}

template <typename T> Node<T> *recurReverse(Node<T> *head) {
  if (head == NULL or head->getNext() == NULL) {
    return head;
  }
  Node<T> *newHead = recurReverse(head->getNext());
  head->getNext()->setNext(head);
  head->setNext(NULL);
  return newHead;
}

template <typename T> void print(Node<T> *head) {
  Node<T> *temp = head;
  while (temp != NULL) {
    cout << temp->getData() << "-->";
    temp = temp->getNext();
  }
  cout << endl;
}

template <typename T> Node<T> *iterReverse(Node<T> *head) {
  Node<T> *prev = NULL;
  Node<T> *curr = head;
  Node<T> *next = NULL;
  while (curr != NULL) {
    next = curr->getNext();
    curr->setNext(prev);
    prev = curr;
    curr = next;
  }
  return prev;
}

int main() {
  Node<int> *head = NULL;
  insertAtHead(head, 1);
  insertAtHead(head, 2);
  insertAtIndex(head, 10, 1);
  insertAtHead(head, 3);
  insertAtHead(head, 4);
  insertAtHead(head, 5);
  print(head);
  Node<int> *temp = iterReverse(head);
  print(temp);
  return 0;
}
