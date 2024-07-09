#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//provided a vector of integers and a target sum, find the triplets that add up to the target sum and keep the final 2d array sorted and each of its element array sorted as well.

vector<vector<int>> find_triplets(vector<int> v, int sum) {
  vector<vector<int>> result;
  //sorting the array to get the final result sorted
  sort(v.begin(), v.end());
  //iterating over the vector and then solving the pair sum problem for the remaining array
  for (int i = 0; i < v.size() - 2; i++) {
    int j = i + 1;
    int k = v.size()-1;

    // two pointer approach
    while (j < k) {
      if (v[j] + v[k] + v[i] == sum) {
        result.push_back({v[i], v[j], v[k]});
        j++;
        k--;
      } else if (v[j] + v[k] + v[i] > sum) {
        k--;
      } else {
        j++;
      }
    }
  }
  return result;
}

int main() {
  vector<int> v {1, 2, 3, 5, 6, 8, 10};
  int sum = 9;
  auto p = find_triplets(v, sum);
  for (auto x : p) {
    cout << "{";
    for (auto y : x)
      cout << y << ",";
    cout << "}" << endl;
  }
  return 0;
}
