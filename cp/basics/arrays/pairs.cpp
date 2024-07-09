#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

//given a vector of integers and a target sum, find all the pairs in the vector that add up to the target sum.

vector<pair<int, int>> find_pairs(vector<int> v, int k) {
  vector<pair<int, int>> result;
  unordered_set<int> s;

  //iterate over the vector.
  for (int x : v) {
    //find out the complementary number for the element.
    int y = k - x;
    //check if the complementary part is present in the set s.
    if (s.find(y) != s.end())
      result.push_back({x, y});

    //insert the element into the set.
    s.insert(x);
  }

  return result;
}

int main() {
  vector<int> v = {1, -2, 2, 3, 4, 5, 6, 7, 8, -3, 3};
  int sum = 6;
  auto p = find_pairs(v, sum);

  for (auto x : p) {
    cout << "(" << x.first << "," << x.second << ")" << endl;
  }
  return 0;
}
