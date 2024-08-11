#include <iostream>
#include <vector>

using namespace std;

// Problem: Given a string containing digits from 2-9 inclusive, return all
// possible letter combinations that the number could represent. Return the
// answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given
// below.
vector<string> keypad = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};

// The function below is a recursive function that takes in a string output, a
// string s, and an integer i. The function prints all possible combinations of
// the letters that the digits in the string s could represent. The function is
// called with the initial values of output = "", s = str, and i = 0.
void printCombinations(string output, string s, int i) {
  // Base case
  if (i == s.length()) {
    cout << output << endl;
    return;
  }

  // Find the index of the digit in the keypad vector
  int ch = s[i] - '0';

  // For each character in the string corresponding to the digit, call the same
  // function with the updated output and i + 1
  for (auto c : keypad[ch]) {
    printCombinations(output + c, s, i + 1);
  }
}

int main() {
  string str, output;
  cin >> str;
  printCombinations(output, str, 0);
  return 0;
}
