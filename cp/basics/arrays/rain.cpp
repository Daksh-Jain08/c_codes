#include <iostream>
#include <vector>

using namespace std;

int water(vector<int> v) {
  int ans = 0;
  int n = v.size();
  if (n <= 2)
    return 0;
  vector<int> right(v.size(), 0), left(v.size(), 0);
  right[n - 1] = v[n - 1];
  left[0] = v[0];

  for (int i = 1; i < n; i++) {
    right[n - 1 - i] = max(right[n - i], v[n - 1 - i]);
    left[i] = max(left[i - 1], v[i]);
  }

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
