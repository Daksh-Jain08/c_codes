#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
given a list of integers, find the length of the longest band that can be
formed by rearraging the list. a band is a sequence of consecutive numbers,
that is, a[i] = a[i+1] - 1.
*/

// The approach here is to use a hash table(unordered set) because we need to
// check for the elements a lot in this problem. we insert the elements in an
// unordered set, then we iterate over the vector. if the element has the number
// just smaller than it, then we just ignore the number, because it cannot be
// the start of a band. when we get an element whose predecessor is not in the
// set, we start checking sequence of consecutive numbers.

int longest_band(vector<int> v) {
  int result = 0;
  unordered_set<int> s;

  //inserting the elements in the unordered set.
  for (int x : v)
    s.insert(x);

  //iterating over the vector. This take O(N)
  for (int element : v) {
    int count = 1;
    int successor = element + 1;
    //increase count till the next consecutive number is found. This lookeup takes O(1)
    while (s.find(element-1) == s.end()) {
      successor++;
      count++;
    }

    //updating result if the current band is greater than result
    result = max(result, count);
  }
  return result;
}

// another approach was to sort the array and then iterate over it to see the
// longest consecutive sequence, but this takes O(logN)

int main() {
  vector<int> v = {1, 9, 3, 0, 18, 5, 2, 10, 7, 12, 6};
  cout << longest_band(v) << endl;

  return 0;
}
