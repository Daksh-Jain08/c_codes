#include <iostream>
#include <vector>

using namespace std;

// Problem: Given a sorted array of strings that is interspersed with empty
// strings, write a method to find the location of a given string.

// Approach: We can use a modified binary search to solve this problem. We can
// use a helper function nearest_non_empty_word to find the nearest non-empty
// word to the mid element. If the mid element is empty, we can find the nearest
// non-empty word to the mid element and then compare the mid element with the
// given string. If the mid element is equal to the given string, we return the
// index of the mid element. If the mid element is greater than the given
// string, we search in the left half of the array. If the mid element is less
// than the given string, we search in the right half of the array.


int nearest_non_empty_word(vector<string> v, int start, int end, int mid) {
  int i = mid;
  int j = mid;
  while (i >= start and j <= end) {
    if (v[i] != "")
      return i;
    if (v[j] != "")
      return j;
    j++;
    i--;
  }
  return -1;
}

int sparseSearch(vector<string> v, string s) {
  int index = -1;
  int start = 0;
  int end = v.size();
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == "")
      mid = nearest_non_empty_word(v, start, end, mid);
    if (mid == -1)
      return -1;
    if (v[mid] == s)
      return mid;
    else if (v[mid] > s) {
      end = mid - 1;
      continue;
    } else {
      start = mid + 1;
      continue;
    }
  }
  return -1;
}

int main() {
  vector<string> v = {"ai", "", "", "", "bat", "cat",
                      "",   "", "", "", "",    "dog"};
  string s = "ait";
  cout << sparseSearch(v, s) << endl;
  return 0;
}
