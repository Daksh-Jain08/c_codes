#include <iostream>
#include <vector>

using namespace std;

// given an array of integers representing the heights of the buildings, find
// the amount of water that can be trapped between the buildings. The width of
// each building is 1.
int water(vector<int> v) {
  int ans = 0;
  int n = v.size();
  // if there are less than 3 buildings, then no water can be trapped.
  if (n <= 2)
    return 0;

  vector<int> right(v.size(), 0), left(v.size(), 0);
  right[n - 1] = v[n - 1];
  left[0] = v[0];

  // find the maximum height of the building to the right and left of each
  // building.
  for (int i = 1; i < n; i++) {
    right[n - 1 - i] = max(right[n - i], v[n - 1 - i]);
    left[i] = max(left[i - 1], v[i]);
  }

  // find the amount of water that can be trapped at each building. The amount
  // of water that can be trapped at each building is the minimum of the maximum
  // height of the building to the right and left of it minus the height of the
  // building.
  for (int i = 0; i < n; i++) {
    int w = min(left[i], right[i]) - v[i];
    if (w > 0)
      ans += w;
  }
  return ans;
}

int main() {
  vector<int> arr = {0, 1, 0, 1, 4, 0, 4};
  int ans = water(arr);
  cout << ans << endl;

  return 0;
}
