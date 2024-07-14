#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Problem: Given an array of integers and an integer k, find the number of
// subarrays with a sum equal to k.

// Approach: We use a map to solve this problem. We keep track of the sum of the
// elements in the array as we iterate through the array. If the sum of the
// elements up to the current index minus k is present in the map, we increment
// the count by the value of the sum in the map. We update the sum in the map by
// incrementing its value by 1.
int cntSubArrays(vector<int> arr, int k) {
  int n = arr.size();
  int cnt = 0;
  unordered_map<int, int> s;

  // To handle the case when the sum of the elements up to the current index is
  // k.
  s[0] = 1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    // If the sum of the elements up to the current index minus k is present in
    // the map, increment the count by the value of the sum in the map.
    // Because between the current index and s[sum - k] other indices, the sum of the elements is k.
    if (s.find(sum - k) != s.end()) {
      cnt += s[sum - k];
    }
    // Update the sum in the map by incrementing its value by 1.
    s[sum]++;
  }
  return cnt;
}

int main() {
  vector<int> arr = {10, 2, -2, -20, 10};
  int k = -10;
  cout << cntSubArrays(arr, k) << endl;
  return 0;
}
