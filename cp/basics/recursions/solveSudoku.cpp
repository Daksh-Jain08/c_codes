#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int>> board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool isPossibleToPlace(vector<vector<int>> board, int i, int j, int k) {
  // Check for row and column
  for (int x = 0; x < 9; x++) {
    if (board[i][x] == k || board[x][j] == k)
      return false;
  }

  // Check for subgrid
  int sx = (i / 3) * 3;
  int sy = (j / 3) * 3;
  for (int x = sx; x < sx + 3; x++) {
    for (int y = sy; y < sy + 3; y++) {
      if (board[x][y] == k)
        return false;
    }
  }

  return true;
}

vector<vector<int>> solveSudoku(vector<vector<int>> board, int i, int j) {
  // Base case
  if (i == 9) {
    printBoard(board);
    return board;
  }

  // Recursive case
  if (board[i][j] != 0) {
    return solveSudoku(board, i + (j + 1) / 9, (j + 1) % 9);
  }
  for (int k = 1; k <= 9; k++) {
    if (isPossibleToPlace(board, i, j, k)) {
      board[i][j] = k;
      vector<vector<int>> success =
          solveSudoku(board, i + (j + 1) / 9, (j + 1) % 9);
      if (success.size() > 0)
        return success;
    }
  }
  board[i][j] = 0;
  return {};
}

int main() {
  vector<vector<int>> board = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 0}};
  solveSudoku(board, 0, 0);
  return 0;
}
