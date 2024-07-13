#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// Implement a function that takes an input a vector of integers, and prints the
// maximum subarray sum that can be formed. A subarray is defined as consecutive
// segment of the array. If all numbers are negative, then return 0.

int maxSubarraySum(vector<int> v) {
  int current = 0;
  int max = INT_MIN;
  for (int x : v) {
    current += x;
    max = std::max(current, max);
    current = std::max(current, 0);
  }
  return std::max(max, 0);
}

int main() {
  vector<int> v = {-1, 6, 1, -5, -3, 2, 3, -2, 6, -8, 3};
  int ans = maxSubarraySum(v);
  cout << ans << endl;
  return 0;
}
