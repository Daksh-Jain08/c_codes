#include <iostream>
#include <vector>

using namespace std;

bool is_possible(vector<int> &arr, int students, int mid) {
  int current = 0;
  int count = 1;
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] > mid)
      return false;
    if (current + arr[i] > mid) {
      count++;
      current = 0;
    }
    current += arr[i];
  }
  return count <= students;
}

int minPages(vector<int> &arr, int n, int m) {
  int ans = 0;
  int start = 0, end = 0;
  for (int x : arr)
    end += x;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (is_possible(arr, m, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {12, 34, 67, 90};
  int n = arr.size();
  int m = 3;
  cout << minPages(arr, n, m) << endl;
  return 0;
}
