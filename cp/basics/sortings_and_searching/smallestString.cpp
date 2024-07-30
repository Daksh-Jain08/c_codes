#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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
