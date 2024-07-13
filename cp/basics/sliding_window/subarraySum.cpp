#include <iostream>
#include <vector>

using namespace std;

// given an array of integers, find all subarrays that sum to a given number.

// the approach here is to use two pointers, start and i. We will keep
// incrementing i till the sum of the subarray is less than the given sum. If
// the sum of the subarray is greater than the given sum, we will keep
// incrementing start till the sum of the subarray is less than the given sum.
// If the sum of the subarray is equal to the given sum, we will add the start
// and i to the vector of pairs and increment start. We will keep doing this
// till i reaches the end of the array.
vector<pair<int, int>> subArraySum(vector<int> arr, int sum) {
  vector<pair<int, int>> v;
  int start = 0;
  int current_sum = arr[0];

  for (int i = 1; i < arr.size();) {
    //incrementing i till the current_sum of the subarray is less than the given sum.
    //this is increasing the size of the subarray.
    while (current_sum < sum) {
      current_sum += arr[i];
      i++;
    }

    //incrementing start till the current_sum of the subarray is greater than the given sum.
    //this is decreasing the size of the subarray.
    while (current_sum > sum and start < i) {
      current_sum -= arr[start];
      start++;
    }

    //if the current_sum of the subarray is equal to the given sum, add the start and i-1 to the vector of pairs.
    if (current_sum == sum) {
      v.push_back({start, i - 1});
      current_sum -= arr[start];
      start++;
    }
  }
  return v;
}

int main() {
  vector<int> arr = {8, 1, 13, 2, 1, 4, 1, 3, 2, 1, 1, 2};
  int sum = 8;
  vector<pair<int, int>> ans = subArraySum(arr, sum);
  for (int i = 0; i < ans.size(); i++) {
    cout << "{" << ans[i].first << ", " << ans[i].second << "}" << endl;
  }
  return 0;
}
