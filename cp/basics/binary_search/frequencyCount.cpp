#include <iostream>
#include <vector>

using namespace std;

// Problem: Given a sorted array, find the frequency of a given element in the
// array.

// Approach: We will use binary search to find the first and last occurrence of
// the element in the array. The frequency will be the difference between the
// two indices + 1.

// Function to perform binary search on the array.
int binarySearch(vector<int> v, int start, int end, int ele) {
  int index = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == ele) {
      index = mid;
      break;
    } else if (v[mid] < ele)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return index;
}

// Function to find the frequency of a given element in the array. We keep two
// variables that store the highest and the lowest index of the element in the
// array. We then find the first occurrence of the element in the array and
// update the lowest index. We then find the last occurrence of the element in
// the array and update the highest index. The frequency will be the difference
// between the highest and the lowest index + 1.
int freqCount(vector<int> v, int k) {
  int count = 0;
  int lowest_idx = v.size(), highest_idx = -1;
  int start = 0, end = v.size();
  int mid = start + (end - start) / 2;
  int idx = binarySearch(v, start, end, k);

  // Find the first occurrence of the element in the array.
  while (idx != -1) {
    lowest_idx = min(lowest_idx, idx);
    // call binary search on the left half of the array.
    idx = binarySearch(v, start, idx - 1, k);
  }

  // Find the last occurrence of the element in the array.
  idx = binarySearch(v, lowest_idx, end, k);
  while (idx != -1) {
    highest_idx = max(highest_idx, idx);
    // call binary search on the right half of the array.
    idx = binarySearch(v, idx + 1, end, k);
  }
  count = highest_idx - lowest_idx + 1;
  // If the element is not present in the array, return 0.
  return max(count, 0);
}

int main() {
  vector<int> v = {0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4};
  int k;
  cin >> k;
  int count = freqCount(v, k);
  cout << count << endl;
  return 0;
}
