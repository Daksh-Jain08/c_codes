#include <iostream>

using namespace std;

// Problem: Given a string s, print all possible permutations of the string.

// Approach: Take out each character from the string and call the function with the remaining string.

void permute(string output, string input) {
  // Base Case
  if (input.length() == 0) {
    cout << output << endl;
    return;
  }

  for (int i = 0; i < input.length(); i++) {
    char ch = input[i];
    // Find the remaining string after removing the character at index i
    string remaining;
    for (int j = 0; j < input.length(); j++) {
      if (j != i)
        remaining += input[j];
    }
    // Call the function recursively with the updated output and remaining string
    permute(output + ch, remaining);
  }
}

int main() {
  string s, output;
  cin >> s;
  permute(output, s);
  return 0;
}
