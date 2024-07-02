#include "header.h"
#include <climits>

Graph::Graph(int **a, int n) {
  nodes = n;
  for (int i = 0; i < n; i++) {
    arr[i] = new int[nodes];
    for (int j = 0; j < n; j++) {
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
  cout << endl;
}

void Graph::depthFirstSearch(int start, int visited[]) {
  visited[start] = 1;
  cout << start << ", ";

  for (int v = 0; v < nodes; v++) {
    if (arr[start][v] != 0 && visited[v] == 0) {
      depthFirstSearch(v, visited);
    }
  }
}

void Graph::primsMSP(int **t, int near[]) {
  int min = INT_MAX;
  int u, v;
  // finding the least costing edge and storing the two vertices in u and v.
  for (int i = 1; i < nodes; i++) {
    for (int j = i; j < nodes; j++) {
      if (arr[i][j] < min) {
        min = arr[i][j];
        u = i;
        v = j;
      }
    }
  }
  // storing the edge in the solution matrix.
  t[0][0] = u;
  t[1][0] = v;

  // updating the near array to keep a record of the nearest vertex among the
  // vertices choosen. The value at the i'th element is the nearer vertex.
  for (int i = 1; i < nodes; i++) {
    if (near[i] != 0 && arr[u][i] < arr[v][i])
      near[i] = u;
    else
      near[i] = v;
  }

  int k = 0;
  for (int i = 1; i < nodes - 1; i++) {
    int min_i = INT_MAX;
    for (int j = 1; j < nodes; j++) {
      if (near[j] != 0 && arr[j][near[j]] < min) {
        min = arr[j][near[j]];
        k = j;
      }
    }

    t[0][i] = k;
    t[1][i] = near[k];
    near[k] = 0;
  }

  for (int j = 1; j < nodes; j++) {
    if (near[j] != 0 && arr[k][j] < arr[near[j]][j])
      near[j] = k;
  }
}

int find(int set[], int index) {
  int x = index;
  while (set[x] > 0)
    x = set[x];
  return x;
}

void unionSet(int set[], int i, int j) {
  if (set[i] < set[j]) {
    set[i] = set[i] + set[j];
    set[j] = find(set, i);
  } else if (set[i] > set[j]) {
    set[j] = set[i] + set[j];
    set[i] = j;
  } else {
    int greater = i > j ? i : j;
    int smaller = i < j ? i : j;
    set[greater] = set[greater] + set[smaller];
    set[smaller] = greater;
  }
}

void Graph::kruskalsMSP(int **t, int num_edges) {
  int set[nodes], included[nodes];
  for (int i = 0; i < nodes; i++)
    set[i] = -1;

  for (int i = 0; i < nodes; i++)
    included[i] = 0;

  int edges[3][num_edges];

  for (int i = 0, k = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      if (arr[i][j] != INT_MAX) {
        edges[0][k] = i;
        edges[1][k] = j;
        edges[2][k++] = arr[i][j];
      }
    }
  }

  int u, v, index;
  int num = 0;
  while (num < nodes - 1) {
    int min = INT_MAX;
    for (int i = 0; i < num_edges; i++) {
      if (included[i] != 1 && edges[2][i] < min) {
        min = edges[2][i];
        u = edges[0][i];
        v = edges[1][i];
        index = i;
      }
    }
    if (find(set, v) != find(set, u)) {
      unionSet(set, find(set, u), find(set, v));
      t[0][num] = u;
      t[1][num] = v;
      num++;
    }
    included[index] = 1;
  }
}
