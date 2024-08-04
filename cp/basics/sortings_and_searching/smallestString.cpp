#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// Problem: Given a list of strings v, return the smallest string that can be
// made by concatenating the strings in v.

// Approach: We can sort the strings in such a way that the smallest string is
// formed. We can use a custom comparator function to sort the strings. The
// comparator function will compare two strings a and b. If a + b < b + a, then
// a is smaller than b. We can sort the strings using this comparator function
// and then concatenate the strings to get the smallest string.
bool comparator(string a, string b) { return a + b < b + a; }

string smallestString(vector<string> v) {
  string a = "";
  sort(v.begin(), v.end(), comparator);
  for (string x : v)
    a += x;
  return a;
}

int main() {
  vector<string> s = {"aba", "ab", "a"};
  string str = smallestString(s);
  cout << str << endl;
  return 0;
}
