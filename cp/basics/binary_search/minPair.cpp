#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Problem: Given two arrays, find the pair of elements (one from each array) with the minimum difference.

// Approach 1: Sort both arrays and compare the elements one by one. Time complexity: O(nlogn + mlogm + n + m) = O(nlogn + mlogm)
pair<int, int> findMinPair(vector<int> v1, vector<int> v2) {
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int min_diff = INT_MAX;
  pair<int, int> ans;
  int i = 0, j = 0;
  while (i < v1.size() && j < v2.size()) {
    if (abs(v1[i] - v2[j]) < min_diff) {
      min_diff = abs(v1[i] - v2[j]);
      ans = {v1[i], v2[j]};
    }
    if (v1[i] < v2[j]) {
      i++;
    } else {
      j++;
    }
  }
  return ans;
}

// Approach 2: Sort one array and perform binary search on the other array for each element. Time complexity: O(nlogn + mlogm)
pair<int, int> findMinPair2(vector<int> v1, vector<int> v2) {
  sort(v1.begin(), v1.end());
  pair<int, int> ans;
  int min_diff = INT_MAX;
  for (int i = 0; i < v2.size(); i++) {
    int idx = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
    if (idx < v1.size() && abs(v1[idx] - v2[i]) < min_diff) {
      min_diff = abs(v1[idx] - v2[i]);
      ans = {v1[idx], v2[i]};
    }
    if (idx > 0 && abs(v1[idx - 1] - v2[i]) < min_diff) {
      min_diff = abs(v1[idx - 1] - v2[i]);
      ans = {v1[idx - 1], v2[i]};
    }
  }
  return ans;
}

int main() {
  vector<int> v1 = {1, 3, 15, 11, 2};
  vector<int> v2 = {23, 127, 235, 19, 8};
  pair<int, int> ans = findMinPair(v1, v2);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
