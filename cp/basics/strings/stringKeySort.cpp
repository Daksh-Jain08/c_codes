#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string extractTokenAtKey(string str, int key) {
  // string tokenisor

  // strtok takes a char* as an input, here str.c_str() gives the underlying c
  // representation of the string object
  char *s = strtok((char *)str.c_str(), " ");

  while (key > 1) {
    s = strtok(NULL, " ");
    key--;
  }

  return (string)s;
}

// Lexicographic comparator
bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
  string key1, key2;
  key1 = s1.second;
  key2 = s2.second;
  return key1 < key2;
}

// function to convert string to integer
int convertToInt(string s) {
  int ans = 0;
  int p = 1;

  int i = s.length();
  while (i >= 0) {
    ans += ((s[i--] - '0') * p);
    p *= 10;
  }

  return ans;
}

// Numeric comparator
bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
  string key1, key2;
  key1 = s1.second;
  key2 = s2.second;
  return convertToInt(key1) < convertToInt(key2);
}

int main() {
  int n;
  cin >> n;

  cin.get(); // consume the extra \n
  vector<string> v;
  string s;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    v.push_back(s);
  }

  int key;
  string reversal, ordering;
  cin >> key >> reversal >> ordering;

  // To extract the key and store them
  vector<pair<string, string>> vp;

  for (int i = 0; i < n; i++) {
    vp.push_back({v[i], extractTokenAtKey(v[i], key)});
  }

  // Sorting
  if (ordering == "numeric") {
    sort(vp.begin(), vp.end(), numericCompare);
  } else
    sort(vp.begin(), vp.end(), lexicoCompare);

  //Reversing the output if needed
  if(reversal == "true")
    reverse(vp.begin(), vp.end());

  //print the output
  for(auto p : vp)
    cout<<p.first<<endl;

  return 0;
}
