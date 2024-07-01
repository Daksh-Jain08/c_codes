#include<iostream>

using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
} node;

class Queue{
  private:
    node* front;
    node* rear;
  public:
    Queue(int n){front = nullptr;}
    node* getFront(){return front;}
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
};

class Graph{
  private:
    int **arr;
    int nodes;
  public:
    Graph(int **a, int n);
    void breadthFirstSearch(int start);
    void depthFirstSearch(int start, int visited[]);
};
