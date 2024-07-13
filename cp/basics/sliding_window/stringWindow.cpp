#include <iostream>
#include <unordered_map>

using namespace std;

// Problem: Given two strings, big and small, find the smallest window in big
// that contains all characters of small. If no such window exists, return an
// empty string.

// This function returns a map with the frequency of each character in the
// string s.
unordered_map<char, int> getStringMap(string s) {
  unordered_map<char, int> s_map;
  for (int i = 0; i < s.size(); i++) {
    if (s_map.find(s[i]) == s_map.end()) {
      s_map[s[i]] = 1;
    } else {
      s_map[s[i]]++;
    }
  }
  return s_map;
}

// This function returns true if the big_map contains the small_map.
bool isSubString(unordered_map<char, int> big_map,
                 unordered_map<char, int> small_map) {
  for (auto it = small_map.begin(); it != small_map.end(); it++) {
    // if a character in small_map is not in big_map, return false
    if (big_map.find(it->first) == big_map.end()) {
      return false;
    }
    // if the frequency of a character in small_map is greater than the one in
    // big_map, return false
    if (big_map[it->first] < it->second) {
      return false;
    }
  }
  return true;
}

// This function inserts a character in the big_map. If the character is not in
// the map, it inserts it with a frequency of 1. Otherwise, it increments the
// frequency by 1.
void insert(unordered_map<char, int> &big_map, char c) {
  if (big_map.find(c) == big_map.end()) {
    big_map[c] = 1;
  } else {
    big_map[c]++;
  }
}

// This is the main function that solves the problem. It uses a sliding window
// approach to find the smallest window in big that contains all characters of
// small.
// It keeps expanding the window from the right until it contains all characters
// of small. Then it keeps shrinking the window from the left until it doesn't
// contain all characters of small. It keeps track of the smallest window found
// so far.
string stringWindow(string big, string small) {
  // if the size of small is greater than the size of big, return an empty
  if (big.size() < small.size()) {
    return "";
  }
  int start_min_window = -1;
  int start = 0;
  int end = 0;
  int size_min_window = big.size() - 1;

  unordered_map<char, int> small_map = getStringMap(small);
  unordered_map<char, int> window_map;

  while (end <= big.size() or isSubString(window_map, small_map)) {
    // if the window doesn't contain all characters of small, expand it
    if (!isSubString(window_map, small_map)) {
      insert(window_map, big[end]);
      end++;
    }
    // update the smallest window if the current window is smaller than the
    // smallest window found so far. Then shrink the window and decrement the
    // frequency of the character that is being removed.
    else {
      int current_size = end - start;
      if (current_size < size_min_window) {
        size_min_window = current_size;
        start_min_window = start;
      }
      window_map[big[start]] = max(0, window_map[big[start]] - 1);
      start++;
    }
  }

  return big.substr(start_min_window, size_min_window);
}

int main() {
  string big, small;
  cin >> big >> small;
  cout << stringWindow(big, small) << endl;
  return 0;
}
