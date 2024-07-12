#include <bits/stdc++.h>

using namespace std;

int skip_whitespaces(const string &str, size_t ind){
  while(ind<str.length() and str[ind] == ' ')
    ind++;
  return ind;
}

int normalise_word(string &str, size_t ind){
  if(ind < str.length() and str[ind] != ' '){
    str[ind] = toupper(str[ind]);
    ind++;
  }

  while(ind<str.length() and str[ind]!=' '){
    str[ind] = tolower(str[ind]);
    ind++;
  }

  return ind;
}

string normalise(string sentence) {
  string copy = sentence;
  size_t i = 0;

  while(i < copy.length()){
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
