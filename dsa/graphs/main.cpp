#include "header.h"

int main() {
  int A[7][7] = {
      {0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 1, 0, 0},
  };

  int nodes = 7;
  int **arr = new int *[nodes];
  for (int i = 0; i < nodes; i++) {
    arr[i] = new int[nodes];
    for (int j = 0; j < nodes; j++) {
      arr[i][j] = A[i][j];
    }
  }

  int visited[nodes];
  for (int i = 0; i < nodes; i++)
    visited[i] = 0;

  Graph gr(arr, 7);
  cout << "Done" << endl;
  gr.depthFirstSearch(4, visited);
  return 0;
}
