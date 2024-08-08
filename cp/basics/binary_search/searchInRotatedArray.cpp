#include <iostream>
#include <vector>

using namespace std;

// Problem: Given a sorted array that has been rotated, find the index of a
// given element in the array.

// Approach: We will use a modified binary search to find the index of the
// element in the array. We will compare the middle element with the start
// element of the array. If the middle element is greater than or equal to the
// start element, then the left half of the array is sorted. If the middle
// element is less than the start element, then the right half of the array is
// sorted. We will then check if the element lies in the sorted half of the
// array. If it does, we will perform a binary search on that half of the array.
// If it does not, we will perform a binary search on the other half of the
// array.

int modifiedBinarySearch(const vector<int> &v, int k) {
  int index = -1;
  int start = 0, end = v.size();
  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (v[mid] == k)
      return mid;

    if (v[mid] >= v[start]) {
      if (v[mid] > k)
        end = mid - 1;
      else
        start = mid + 1;
    }

    else {
      if (v[mid] > k)
        start = mid + 1;
      else
        end = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> v = {4, 5, 6, 7, 0, 1, 2, 3};
  int k;
  cin >> k;
  cout << modifiedBinarySearch(v, k) << endl;
  return 0;
}
