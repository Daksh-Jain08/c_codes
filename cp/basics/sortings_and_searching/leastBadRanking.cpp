#include <iostream>
#include <vector>

using namespace std;

int leastBadRanking(vector<pair<string, int>> arr) {
  vector<int> v(arr.size() + 1, 0);
  for (auto x : arr)
    v[x.second]++;
  int pos = 1;
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    while (v[i] > 0) {
      cout << i << endl;
      sum += abs(i - pos);
      pos++;
      v[i]--;
    }
  }
  return sum;
}

int main() {
  vector<pair<string, int>> v = {
      {"WinOrBooze", 1},   {"BallOfDuty", 2}, {"WhoKnows", 2},
      {"BholeChature", 1}, {"DECoders", 5},   {"StrangeCase", 7},
      {"WhoKnows", 7},
  };
  int ans = leastBadRanking(v);
  cout << ans << endl;
  return 0;
}
