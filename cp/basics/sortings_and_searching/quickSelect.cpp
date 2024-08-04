#include <iostream>
#include <vector>

using namespace std;

// Problem: Given an array of distinct integers and an index k, find the kth
// smallest element in the array.

// Brute Force approach: Sort the array and return the element at the kth
// position. This approach take average time of O(NlogN)

// Optimal approach: Use something like a quicksort algorithm because in
// quicksort, a selected element is put into its correct position in the sorted
// array. We can start putting element in their correct index and partitioning
// the array. If the array is {0, 5, 2, 3, 1} and k=3, then we first put 1 at
// its correct position. After this, the array becomes {0,1,2,3,5}, the correct
// index of 3 is 3, therefore 3 is the answer, it happened so that the array has
// been sorted in this process it is not necessary always.

int partition(vector<int> &arr, int start, int end) {
  int pivot = arr[end];
  int i = start - 1;
  for (int j = start; j < end; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[end]);
  return i + 1;
}

int quickSelect(vector<int> &arr, int start, int end, int k) {
  if (start == end) {
    return arr[start];
  }
  // put the last element in its correct index and partition the array.
  int pivot = partition(arr, start, end);
  // If the returned index = k, return arr[index]
  if (pivot == k - 1) {
    return arr[pivot];
  }
  // If the returned index < k - 1, this means the desired element is in the
  // right half of the array.
  else if (pivot < k - 1) {
    return quickSelect(arr, pivot + 1, end, k);
  }
  // If the returned index > k - 1, this means the desired element is in the
  // left half of the array.
  else {
    return quickSelect(arr, start, pivot - 1, k);
  }
}

int main() {
  vector<int> arr = {0, 5, 2, 3, 1};
  int k = 2;
  cout << quickSelect(arr, 0, arr.size() - 1, k) << endl;
  return 0;
}
