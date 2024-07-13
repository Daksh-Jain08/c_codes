#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// given a string s, find the longest substring without repeating characters.

// Approach: We will use a sliding window approach to solve this problem.
// We will keep track of the start and end of the window. We will keep a map to
// store the last occurence of a character. If the character is already in the
// window, we will start a new window from the last occurence of the character
// + 1. We will keep track of the window length and the maximum window length so
// far. We will return the substring from the start of the largest window to the
// end of the largest window.
string uniqueSubstring(string s) {
  int start = 0;
  int end = 0;
  int window_length = 0;
  int max_window_length = 0;
  int start_max_window = -1;

  unordered_map<char, int> m;

  while (end < s.length()) {
    char ch = s[end];

    // If the character is already in the window, start a new window from the
    // last occurence of the character + 1.
    if (m.find(ch) != m.end() and m[ch] >= start) {
      start = m[ch] + 1;
      window_length = end - start;
    }

    // Add the character to the map.
    m[ch] = end;
    window_length++;
    end++;

    // Check if the current window length is greater than the largest window so
    // far, and point a variable to the start of the largest window.
    if (window_length > max_window_length) {
      max_window_length = window_length;
      start_max_window = start;
    }
  }
  return s.substr(start_max_window, max_window_length);
}

int main() {
  string s;
  cin >> s;
  string ans = uniqueSubstring(s);
  cout << ans << endl;
  return 0;
}
