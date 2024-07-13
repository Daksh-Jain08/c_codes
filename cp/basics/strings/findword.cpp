#include <bits/stdc++.h>
using namespace std;

// given a big string and a small string, find all the occurrences of the small
// and return the indices.
vector<int> stringSearch(string big, string small) {
  // store the occurrences in the result vector
  vector<int> result = {};
  int index = big.find(small);
  int i = 0;
  while (index != -1) {
    result.push_back(index);
    if (index + 1 < big.length())
      index = big.find(small, index + 1);
  }
  return result;
}

int main() {
  string big = "This is a very very big string and it is very likely that "
               "there are more than one very in this line";
  string small = "very";
  vector<int> a = stringSearch(big, small);
  for (int x : a)
    cout << x << ",";
  cout << endl;
  return 0;
}
