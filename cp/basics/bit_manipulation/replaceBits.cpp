#include <iostream>

using namespace std;

// this function will clear the bits from i to j in n.
void clearBitsInRange(int &n, int i, int j) {
  int a = -1 << (j + 1);
  int b = (1 << i) - 1;
  int mask = (a | b);
  n = n & mask;
}

// given two integers n and m, and two integers i and j, replace the bits in n from i to j with the bits in m.

void replaceBits(int &n, int m, int i, int j){
  // Clear the bits from i to j.
  clearBitsInRange(n, i, j);
  // Shift m i times to the left.
  int mask = m << i;
  // If we do a bitwise OR with n, we will set the bits from i to j to the bits
  n = n | mask;
}

int main() {
  int n,m,i,j;
  cin >> n >> m >> i >> j;
  replaceBits(n,m,i,j);
  cout << n << endl;
  return 0;
}
