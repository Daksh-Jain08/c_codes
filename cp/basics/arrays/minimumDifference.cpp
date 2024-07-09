#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Implement a function that takes in two non-empty arrays of integers, finds
// the pair of numbers (one from each array) who absolute difference is closest
// to zero, and returns a pair containing these two numbers, with the first
// number from array. Only one such pair will exist for the test.
pair<int, int> minDifference(vector<int> a, vector<int> b) {
  // Complete this method
  pair<int, int> ans;
  int min = INT_MAX;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int n = a.size(), m = b.size();

  int i = 0, j = 0;

  while (i < n and j < m) {
    int diff = abs(a[i] - b[j]);
    if (diff < min) {
      min = diff;
      ans = {a[i], b[j]};
    }
    if (a[i] < b[j])
      i++;
    else
      j++;
  }

  return ans;
}

int main() {
  vector<int> a = {23, 5, 10, 17, 30};
  vector<int> b = {26, 134, 135, 14, 19};
  pair<int, int> ans = minDifference(a, b);
  cout << ans.first << "," << ans.second << endl;
  return 0;
}
