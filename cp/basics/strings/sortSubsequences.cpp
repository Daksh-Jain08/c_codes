#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
// given a string, list all the possible subsets in a sorted order, firstly by
// length and if the length is equal then in lexicographical order. For example
// input "abdc" should give the output
//,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd

void subsequence(string str, string output, vector<string> &v) {

  // base case
  if (str.size() == 0) {
    v.push_back(output);
    return;
  }

  // recursive case
  char ch = str[0];
  string reduced_input = str.substr(1);
  // excluding the current letter
  subsequence(reduced_input, output + ch, v);
  // including the current letter
  subsequence(reduced_input, output, v);
}

bool compare(string s1, string s2) { return s1.length() < s2.length(); }

int main() {
  string str;
  cin >> str;

  sort(str.begin(), str.end());

  vector<string> v;
  string output = "";
  subsequence(str, output, v);

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ",";

  cout << endl;
  return 0;
}
