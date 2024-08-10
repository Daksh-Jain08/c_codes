#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_place(vector<int> v, int num, int space) {
  int birds = 1;
  int last_bird = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] - last_bird >= space) {
      birds++;
      last_bird = v[i];
    }
    if (birds == num) {
      return true;
    }
  }
  return false;
}

int angryBirds(vector<int> v, int num) {
  int ans = -1;
  int start = 0, end = v[v.size() - 1] - v[0];
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (can_place(v, num, mid)) {
      ans = max(ans, mid);
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  vector<int> v = {1, 2, 4, 8, 9, 10, 12, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
  sort(v.begin(), v.end());
  int num_of_birds;
  cin >> num_of_birds;
  cout << angryBirds(v, num_of_birds) << endl;
  return 0;
}
