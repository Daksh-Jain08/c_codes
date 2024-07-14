#include<iostream>
#include<deque>
#include<vector>

using namespace std;

// Problem: Given an array of integers and an integer k, find the maximum for each and every contiguous subarray of size k.

// Approach: We use a deque to solve this problem. The deque stores the indices of the elements in the current window in decreasing order of their values. The front of the deque contains the index of the maximum element in the current window. We process the first k elements separately and then process the remaining elements. For each element, we remove elements from the front of the deque that are outside the current window, remove elements from the back of the deque that are smaller than the current element, and add the current element to the back of the deque. The front of the deque contains the index of the maximum element in the current window.
vector<int> maximumInWindow(vector<int> arr, int k) {
  vector<int> result;
  deque<int> dq;

  // Process the first k elements
  for (int i = 0; i < k; i++) {
    // Remove elements from the back of the deque that are smaller than the current element
    while (!dq.empty() && arr[i] >= arr[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }

  // Process the remaining elements
  for (int i = k; i < arr.size(); i++) {
    // The front of the deque contains the index of the maximum element in the current window
    result.push_back(arr[dq.front()]);

    // Remove elements from the front of the deque that are outside the current window
    while (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }

    // Remove elements from the back of the deque that are smaller than the current element
    while (!dq.empty() && arr[i] >= arr[dq.back()]) {
      dq.pop_back();
    }

    dq.push_back(i);
  }

  // Add the maximum element of the last window
  result.push_back(arr[dq.front()]);
  return result;
}

int main() {
  vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
  int k = 3;
  vector<int> result = maximumInWindow(arr, k);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}
