#include <iostream>

using namespace std;

// Problem: Given an integer n, generate all combinations of well-formed
// brackets of length 2 * n.

// The function below is a recursive function that takes in a string output, an
// integer n, and three integers open, close, and current.
void generateBrackets(string output, int n, int open, int close, int current) {
  // Base case
  if (current == n * 2) {
    cout << output << endl;
    return;
  }

  // If the number of open brackets is less than n, add an open bracket and call
  // the function recursively
  if (open < n) {
    generateBrackets(output + '(', n, open + 1, close, current + 1);
  }

  // If the number of close brackets is less than the number of open brackets,
  // add a close bracket and call the function recursively
  if (close < open) {
    generateBrackets(output + ')', n, open, close + 1, current + 1);
  }
}

int main() {
  string output;
  int n;
  cin >> n;
  generateBrackets(output, n, 0, 0, 0);
  return 0;
}
