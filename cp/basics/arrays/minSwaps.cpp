#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// find the minimum number of swaps required to sort a given array.

// we sort the array to find the correct position of the elements, then we
// iterate over the array and try to send each element to its correct place, say
// the array is {2,4,5,1,3} then 2 should go in place of 4, but where should 4
// go? it should go the place of 1 and 1 should go to the place of 2, this is a
// cycle, the cycle has 3 elements, this cycle can be fixed in 2 swaps, then we
// go ahead, 4 has been resolved so we move forward, now 5 should go in the
// place of 3 and 3 should come in the place of 5, this is a cycle of 2 elements
// and can be resolved in 1 swap. total swaps required = 2+1 = 3.
int minSwaps(vector<int> v) {
  int swaps = 0;
  int n = v.size();

  // store the current indices of the elements in the unsorted array
  pair<int, int> ap[n];
  for (int i = 0; i < v.size(); i++) {
    ap[i].first = v[i];
    ap[i].second = i;
  }

  // sort the array of pairs.
  sort(ap, ap + n);

  // this will help us to keep a track of the elements that have been taken care
  // of
  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    // do nothing if the element is in the right position or has been visited
    if (visited[i] == true or ap[i].second == i)
      continue;

    // if the element has not been visited and is not in the right position
    else {
      int j = i;
      int cycle = 0;
      // count the number of elements that form the cycle of swappings
      while (!visited[j]) {
        visited[j] = true;
        j = ap[j].second;
        cycle++;
      }

      // the number of swaps to fix a cycle with n elements is n-1
      swaps += cycle - 1;
    }
  }

  return swaps;
}

int main() {
  vector<int> v = {10, 11, 5, 4, 3, 2, 1};
  int n = minSwaps(v);
  cout << n << endl;
  return 0;
}
