#include <iostream>
#include <vector>

using namespace std;

// Problem: Given a 2D vector of integers that is sorted in ascending order in
// both rows and columns, write a method to find the location of a given
// integer.

// Approach: We can use a staircase search to solve this problem. We can start
// from the top right corner of the 2D vector. If the element at the current
// position is equal to the given integer, we return the current position. If
// the element at the current position is greater than the given integer, we
// move left. If the element at the current position is less than the given
// integer, we move down. We continue this process until we find the given
// integer or reach the end of the 2D vector.

pair<int, int> staircaseSearch(vector<vector<int>> v, int x) {
  int row = 0;
  int col = v[0].size() - 1;
  while (row < v.size() and col >= 0) {
    if (v[row][col] == x)
      return {row, col};
    else if (v[row][col] > x)
      col--;
    else
      row++;
  }
  return {-1, -1};
}

int main() {
  vector<vector<int>> v = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int x = 10;
  pair<int, int> ans = staircaseSearch(v, x);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
