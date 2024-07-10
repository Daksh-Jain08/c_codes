#include <bits/stdc++.h>

using namespace std;
// Convert each number in the vector to a string representation. Define a custom
// comparator function that compares two strings by concatenating them in
// different orders and checking which order produces a lexicographically larger
// number and sort the string representations of numbers using the custom
// comparator. Concatenate the sorted strings to form the lexicographically
// largest number.

//this is the function that i made while i solved the problem. i iterate over all the digits from left to right, if any one of the digit differs, the greater one is returned. if the digits then i check if the smaller one's last digit is greater than the larger one's next index(smaller last index + 1), if so, i return smaller one to be put forward in sorting.
bool compare(int a, int b) {
  cout << a << "," << b << endl;
  string str_a = to_string(a);
  string str_b = to_string(b);
  int i = 0;
  while (i < str_a.length() and i < str_b.length()) {
    if (str_a[i] > str_b[i])
      return true;
    else if (str_a[i] < str_b[i])
      return false;
    i++;
  }
  string greater = str_a.length() > str_b.length() ? str_a : str_b;
  string smaller = str_a.length() < str_b.length() ? str_a : str_b;
  if (greater[i] >= smaller[i - 1]) {
    if (str_a == greater)
      return true;
    else
      return false;
  } else {
    if (smaller == str_a)
      return true;
    else
      return false;
  }
}

//this is the solution comparator and this should have been intuitive
//this comparator just returns 'a' to be put before b if doing so gives us bigger number.
bool compare_better(int a, int b){
  string str_a = to_string(a);
  string str_b = to_string(b);
  return str_a+str_b>str_b+str_a;

}

string concatenate(vector<int> v) {
  sort(v.begin(), v.end(), compare_better);
  string number = "";
  for (int x : v)
    number += to_string(x);
  return number;
}

int main() {
  vector<int> v;
  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  string number = concatenate(v);
  cout << number << endl;
}
