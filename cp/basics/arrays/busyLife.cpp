#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int countActivities(vector<pair<int, int>> activities) {
  int count = 0;
  sort(activities.begin(), activities.end(), comparator);

  int end = 0;
  for (auto x : activities) {
    if (end <= x.first) {
      count++;
      end = x.second;
    }
  }

  return count;
}

int main() {
  vector<pair<int, int>> v = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};
  cout << countActivities(v) << endl;
  return 0;
}
