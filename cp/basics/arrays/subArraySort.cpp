#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> subArraySort(vector<int> v) {
  int n = v.size();
  int max_unsorted, min_unsorted;
  min_unsorted = INT32_MAX;
  max_unsorted = INT32_MIN;

  for (int i = 1; i < n - 1; i++) {
    if (v[i] < v[i - 1] or v[i] > v[i + 1]) {
      max_unsorted = max(v[i], max_unsorted);
      min_unsorted = min(v[i], min_unsorted);
    }
  }

  if (v[0] > v[1]) {
    min_unsorted = min(min_unsorted, v[0]);
    max_unsorted = max(min_unsorted, v[0]);
  }

  if (v[n - 1] < v[n - 2]) {
    min_unsorted = min(min_unsorted, v[n - 1]);
    max_unsorted = max(min_unsorted, v[n - 1]);
  }

  int i = 0, j = n - 1;
  while (i < n and v[i] < min_unsorted)
    i++;
  while (j >= 0 and v[j] > max_unsorted)
    j--;

  if (i == n)
    return {-1, -1};

  return {i, j};
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  pair<int, int> res = subArraySort(v);
  cout << "{" << res.first << "," << res.second << "}" << endl;
  return 0;
}
