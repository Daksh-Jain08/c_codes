#include <iostream>

using namespace std;

void printBoard(int n, int board[][20]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool isPossibleToPlace(int n, int board[][20], int i, int j) {
  // Column
  for (int k = i; k >= 0; k--) {
    if (board[k][j] == 1)
      return false;
  }

  // Left Diagonal
  int x = i;
  int y = j;
  while (x >= 0 and y >= 0) {
    if (board[x][y] == 1)
      return false;
    x--;
    y--;
  }

  // Right Diagonal
  x = i;
  y = j;
  while (x >= 0 and y < n) {
    if (board[x][y] == 1)
      return false;
    x--;
    y++;
  }

  return true;
}

bool solveNQueens(int n, int board[][20], int i) {
  // Base case
  if (i == n) {
    // Print the Board
    printBoard(n, board);
    return true;
  }

  // Recursive Case
  for (int j = 0; j < n; j++) {
    // Check if placing a queen is possible for this j
    if (isPossibleToPlace(n, board, i, j)) {
      board[i][j] = 1;
      bool success = solveNQueens(n, board, i + 1);
      if (success)
        return true;
      // Backtrack
      board[i][j] = 0;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  int board[20][20] = {0};
  solveNQueens(n, board, 0);
  return 0;
}
