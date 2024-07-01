#include "header.h"

Graph::Graph(int **a, int n){
  nodes = n;
  for(int i = 0; i<n; i++){
    arr[i] = new int[nodes];
    for(int j = 0; j<n; j++){
      arr[i][j] = a[i][j];
    }
  }
}

void Graph::breadthFirstSearch(int start) {
  int visited[nodes];
  for (int i = 0; i < nodes; i++)
    visited[i] = 0;
  visited[start] = 1;

  Queue q(nodes);
  q.enqueue(start);
  cout << start << ", ";
  while (!q.isEmpty()) {
    int u = q.dequeue();
    for (int v = 0; v < nodes; v++) {
      if (arr[u][v] != 0 && visited[v] == 0) {
        cout << v << ", ";
        visited[v] = 1;
        q.enqueue(v);
      }
    }
  }
  cout<<endl;
}

void Graph::depthFirstSearch(int start, int visited[]){
  visited[start] = 1;
  cout<<start<<", ";

  for(int v = 0; v<nodes; v++){
    if(arr[start][v]!=0 && visited[v]==0){
      depthFirstSearch(v, visited);
    }
  }
}
