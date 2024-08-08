#include <iostream>
#include <vector>

using namespace std;

// Problem: Given an array of integers containing only 0s, 1s, and 2s, write a
// method to sort the array in ascending order.

// Approach: We can use the Dutch National Flag algorithm to solve this problem.
// We can use three pointers, low, mid, and high, to keep track of the positions
// of 0s, 1s, and 2s, respectively. We can iterate through the array and swap
// the elements based on the values at the mid pointer. If the mid element is 0,
// we swap it with the low element and increment the low pointer. If the mid
// element is 2, we swap it with the high element and decrement the high
// pointer. If the mid element is 1, we increment the mid pointer.
// This is the most optimal solution to this problem with O(n) time complexity
// with just one pass.

void dnf(vector<int> &v) {
  int low = 0, mid = 0, high = v.size() - 1;
  while (mid <= high) {
    if (v[mid] == 0) {
      swap(v[low], v[mid]);
      low++;
      mid++;
    } else if (v[mid] == 2) {
      swap(v[high], v[mid]);
      high--;
    } else {
      mid++;
    }
  }
}

int main() {
  vector<int> v = {1, 2, 0, 0, 0, 1, 1, 2, 0, 2, 1};
  dnf(v);
  for (int x : v)
    cout << x << ", ";
  cout << endl;
}
