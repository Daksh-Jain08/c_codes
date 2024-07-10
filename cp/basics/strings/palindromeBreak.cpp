#include <iostream>

using namespace std;
// Given a palindromic string of lowercase English letters palindrome, replace
// exactly one character with any lowercase English letter so that the resulting
// string is not a palindrome and that it is the lexicographically smallest one
// possible.

// Return the resulting string.If there is no way to replace a character to make
// it not a palindrome,
// return an empty string.

string breakPalindrome(string s) {
  if (s.length() == 1)
    return "";

  string str = s;
  int i = 0;
  int j = s.length() - 1;
  while (i < j and str[i] == 'a') {
    i++;
    j--;
  }
  if (i < j) {
    s[i] = 'a';
  } else {
    s[s.length() - 1] = 'b';
  }

  return s;
}

int main() {
  string s;
  cin >> s;
  string str = breakPalindrome(s);
  cout << str << endl;
  return 0;
}
