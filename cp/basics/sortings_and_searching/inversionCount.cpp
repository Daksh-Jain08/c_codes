#include <iostream>
#include <vector>

using namespace std;

// Problem: Given an array of integers, find the number of inversions in the array. Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Approach: We can solve this problem using merge sort. The idea is to count the number of inversions in the left half of the array, number of inversions in the right half of the array and number of inversions that cross the mid point. The number of inversions that cross the mid point can be calculated by merging the two halves of the array and counting the number of inversions while merging. We are using a Divide and Conquer approach to solve this problem.

// This function merges the two halves of the array and counts the number of inversions that cross the mid point.
int merge(vector<int> &arr, int start, int mid, int end) {
  int i = start, j = mid + 1, k = 0;
  int count = 0;
  vector<int> temp(end - start + 1);
  while(i <=mid and j <= end) {
    if(arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      // If arr[i] > arr[j], then arr[i] will be greater than all the elements from arr[i] to arr[mid] as the array is sorted. So, we add mid - i + 1 to the count.
      count += mid - i + 1;
    }
  }
  while(i <= mid) {
    temp[k++] = arr[i++];
  }
  while(j <= end) {
    temp[k++] = arr[j++];
  }
  for(int i = start, k = 0; i <= end; i++, k++) {
    arr[i] = temp[k];
  }
  return count;
}

int countInversion(vector<int> &arr, int start, int end) {
  if(start >= end) {
    return 0;
  }
  int mid = start + (end - start) / 2;
  int count = 0;
  // Count the number of inversions in the left half of the array.
  count += countInversion(arr, start, mid);
  // Count the number of inversions in the right half of the array.
  count += countInversion(arr, mid + 1, end);
  // Count the number of inversions that cross the mid point.
  count += merge(arr, start, mid, end);
  return count;
}

int main() {
  vector<int> arr = {0, 5, 2, 3, 1};
  cout << countInversion(arr, 0, arr.size() - 1) << endl;
  return 0;
}
