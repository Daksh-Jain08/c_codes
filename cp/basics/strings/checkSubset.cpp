#include <iostream>

using namespace std;

bool checkSubset(string big, string small) {
  int i = big.length() - 1;
  int j = small.length() - 1;

  while (j >= 0) {
    while (i > 0 and big[i] != small[j])
      i--;
    if (i < 0)
      return false;

    i--;
    j--;
  }
  return true;
}

int main() {
  string big, small;
  getline(cin, big);
  getline(cin, small);

  if (checkSubset(big, small))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
