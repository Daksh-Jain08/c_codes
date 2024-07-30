#include <iostream>
#include <vector>

using namespace std;

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
  int pivot = partition(arr, start, end);
  if (pivot == k - 1) {
    return arr[pivot];
  } else if (pivot < k - 1) {
    return quickSelect(arr, pivot + 1, end, k);
  } else {
    return quickSelect(arr, start, pivot - 1, k);
  }
}

int main() {
  vector<int> arr = {0, 5, 2, 3, 1};
  int k = 2;
  cout << quickSelect(arr, 0, arr.size() - 1, k) << endl;
  return 0;
}
