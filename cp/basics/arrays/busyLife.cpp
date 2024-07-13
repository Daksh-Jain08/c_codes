#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// given a list of activities with start and end times, find the maximum number
// of activities that can be performed.

// this is a comparator function that sorts the activities based on their end
// time.
bool comparator(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

// function to count the number of activities that can be performed
int countActivities(vector<pair<int, int>> activities) {
  int count = 0;

  // sort the activities based on their end time, the activity that ends first
  // is at the front
  sort(activities.begin(), activities.end(), comparator);

  // the idea is to select the activity that ends first and then select the next
  // activity that starts after the current activity ends.
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
