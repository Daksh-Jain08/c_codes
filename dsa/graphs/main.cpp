#include "header.h"
#define I INT_MAX

int main() {
  cout<<"Here";
  int A[][8] = {
      {2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647,
       2147483647, 2147483647},
      {2147483647, 2147483647, 25, 2147483647, 2147483647, 2147483647, 5,
       2147483647},
      {2147483647, 25, 2147483647, 12, 2147483647, 2147483647, 2147483647, 10},
      {2147483647, 2147483647, 12, 2147483647, 8, 2147483647, 2147483647,
       2147483647},
      {2147483647, 2147483647, 2147483647, 8, 2147483647, 16, 2147483647, 14},
      {2147483647, 2147483647, 2147483647, 2147483647, 16, 2147483647, 20, 18},
      {2147483647, 5, 2147483647, 2147483647, 2147483647, 20, 2147483647,
       2147483647},
      {2147483647, 2147483647, 10, 2147483647, 14, 18, 2147483647, 2147483647},
  };
  cout<<"Here";

  int nodes = 8;
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
  gr.depthFirstSearch(4, visited);
  cout << endl;

  int near[nodes];
  for (int i = 0; i < nodes; i++)
    near[i] = I;

  int **t = new int *[2];
  t[0] = new int[nodes - 1];
  t[1] = new int[nodes - 1];

  gr.primsMSP(t, near);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      cout << t[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}
