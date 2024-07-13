#include <iostream>
#include <unordered_map>

using namespace std;

// Problem: Given a string, find the smallest window (substring) which contains
// all distinct characters of the given input string.

// Approach: We use a sliding window approach to solve this problem.
// We find out the number of distinct characters in the string.
// Then, we keep two pointers start and end to represent the window. We keep
// expanding the window from the right until it contains all distinct characters
// of the input string. Then we keep shrinking the window from the left until it
// doesn't contain all distinct characters of the input string. We keep track of
// the smallest window found so far.
string smallestWindow(string s) {
  // if the size of s is 0, return an empty string
  if (s.size() == 0)
    return "";

  int distinct_cnt = 0;
  unordered_map<char, int> distinct_chars;

  // find the number of distinct characters in the string
  for (int i = 0; i < s.size(); i++) {
    if (distinct_chars.find(s[i]) == distinct_chars.end()) {
      distinct_chars[s[i]] = 1;
      distinct_cnt++;
    }
  }
  // clear the map
  distinct_chars.clear();

  int start = 0, end = 0, window_count = 0, min_win_len = s.size(),
      min_win_start = -1;

  // Try to find the smallest window that contains all distinct characters till
  // the end of the string
  while (end < s.size() or window_count >= distinct_cnt) {
    // if the window doesn't contain all distinct characters, expand the window
    if (window_count < distinct_cnt) {
      // if the character is not in the map, insert it with a frequency of 1 and
      // increment window_count
      if (distinct_chars.find(s[end]) == distinct_chars.end()) {
        distinct_chars[s[end]] = 1;
        window_count++;
      }
      // if the character is in the map, increment its frequency
      else
        distinct_chars[s[end]]++;

      end++;
    } else {
      int current_win_len = end - start;
      // if the current window is smaller than the smallest window found so far,
      // update the smallest window
      if (current_win_len <= min_win_len) {
        min_win_len = current_win_len;
        min_win_start = start;
      }

      // if the character at the start of the window has a frequency of 1,
      // remove it from the map and decrement window_count
      if (distinct_chars[s[start]] == 1) {
        distinct_chars.erase(s[start]);
        window_count--;
      }
      // if the character at the start of the window has a frequency greater
      // than 1, decrement its frequency
      else
        distinct_chars[s[start]]--;

      start++;
    }
  }
  return s.substr(min_win_start, min_win_len);
}

int main() {
  string s;
  cin >> s;
  cout << smallestWindow(s) << endl;
  return 0;
}
