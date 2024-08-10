#include <iostream>
#include <vector>

using namespace std;

// Problem: You and your k friends are playing a game where you have to divide
// the money among yourselves. You have to divide the money in such a way that
// each person gets a non-empty contiguous subarray of the given array of money.
// Your friends are greedy and they want to maximize the money they get.
// Therefore they will always choose the subarray with the maximum sum and you
// will get the remaining money. You have to divide the array into k-1 parts to
// give to your friends. You have to find the maximum amount of money you can
// get.

// This function returns if we can get atleast mid amount of money by dividing
// the array into k-1 parts.
bool isPossible(vector<int> v, int k, int mid) {
  int n = v.size();
  int count = 1;
  int current = 0;
  for (int i = 0; i < n; i++) {
    current += v[i];
    if (current >= mid) {
      count++;
      current = 0;
    }
    if (count > k) {
      return true;
    }
  }
  return false;
}

// Approach: We find out if we can get atleast mid amount of money by dividing
// the array into k-1 parts. If we can, then we check if we can get more money
// by increasing the mid value. If we can't, then we check if we can get more
// money by decreasing the mid value. We keep doing this until start <= end. The
// maximum amount of money we can get is stored in ans.
// We use binary search to find the maximum amount of money we can get because
// it is a monotonous search space. Time complexity: O(nlog(sum of all elements
// in the array))
int maxMoney(vector<int> v, int k) {
  int n = v.size();
  int start = 0;
  int end = 0;
  for (int x : v)
    end += x;

  int ans = start;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    // If we can get atleast mid amount of money, try to get more money
    if (isPossible(v, k, mid)) {
      ans = mid;
      start = mid + 1;
    }
    // If we can't get atleast mid amount of money, try to get less money
    else {
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  int k = 2;
  cout << maxMoney(v, k) << endl;
  return 0;
}
