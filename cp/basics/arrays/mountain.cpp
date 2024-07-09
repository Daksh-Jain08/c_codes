#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// given a vector of integers, find the length of the longest mountain. A
// mountain is the sequence where the numbers strictly increase and reach a peak
// and then strictly decrease.
int longest_mountain(vector<int> v) {
  int longest = 0, up = 0, down = 0;
  for (int i = 1; i < v.size(); ++i) {
    if (down and v[i - 1] < v[i] || v[i] == v[i - 1])
      up = down = 0;
    up += v[i - 1] < v[i];
    down += v[i - 1] > v[i];
    if (down and up)
      longest = max(down + up + 1, longest);
  }

  return longest;
}

//we find a peak, i.e, an element which is greater than both its neighbour, then we count the elements in the uphill side and in the downhill side.
int longest_mountain1(vector<int> v) {
  int longest = 0;
  for (int i = 1; i < v.size() - 2;) {
    if (v[i] > v[i - 1] and v[i] > v[i + 1]) {
      int current = 1;
      int j = i;
      while (j >= 1 and v[j] > v[j - 1]) {
        current++;
        j--;
      }

      while (i <= v.size() - 2 and v[i] > v[i + 1]) {
        current++;
        i++;
      }
      longest = max(current, longest);
    }

    else
      i++;
  }
  return longest;
}

int main() {
  vector<int> v = {5, 6, 1, 2, 3, 13, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
  cout << longest_mountain(v) << endl;
  cout << longest_mountain1(v) << endl;
  return 0;
}
