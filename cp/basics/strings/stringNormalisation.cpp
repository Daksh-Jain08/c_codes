#include <bits/stdc++.h>

using namespace std;
// You are given a sentence with words separated by spaces.
// Your task is to:
//  Write a function that returns a copy of this sentence where all the words:
//    start with a capital letter
//    the rest of the letters are lower case

// skip the whitespaces
int skip_whitespaces(const string &str, size_t ind) {
  while (ind < str.length() and str[ind] == ' ')
    ind++;
  return ind;
}

// take the index at which a word is starting and then make the first letter
// capital and the rest small
int normalise_word(string &str, size_t ind) {
  if (ind < str.length() and str[ind] != ' ') {
    str[ind] = toupper(str[ind]);
    ind++;
  }

  while (ind < str.length() and str[ind] != ' ') {
    str[ind] = tolower(str[ind]);
    ind++;
  }

  return ind;
}

// calls the helper functions correctly and normalizes the entire sentence
string normalise(string sentence) {
  string copy = sentence;
  size_t i = 0;

  while (i < copy.length()) {
    i = skip_whitespaces(copy, i);
    i = normalise_word(copy, i);
  }

  return copy;
}

int main() {
  string str;
  getline(cin, str);
  string s = normalise(str);
  cout << s << endl;
  return 0;
}
