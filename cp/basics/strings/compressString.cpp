#include <iostream>

using namespace std;

// Write a function to perform basic string compression using the counts of
// repeated characters, also known as Run Length Encoding. Let see one example,
// the input string "aaaabcccccaaa" would become "a4b1c5a3". If the "compressed"
// string would not become smaller than the original string, your function
// should return the input string.

string compressString(const string &str) {
  string s;
  char ch = str[0];
  s += ch;
  int count = 1;
  int i = 1;
  while (i < str.length()) {
    if (str[i] == ch) {
      count++;
    } else {
      s += to_string(count);
      ch = str[i];
      s += ch;
      count = 1;
    }
    i++;
  }
  s += to_string(count);
  if (s.length() >= str.length())
    return str;
  return s;
}

int main() {
  string s;
  cin >> s;
  string compressed;
  compressed = compressString(s);
  cout << compressed << endl;
  return 0;
}
