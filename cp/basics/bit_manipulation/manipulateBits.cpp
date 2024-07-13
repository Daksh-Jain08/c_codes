#include <iostream>

using namespace std;

int getIthBit(int n, int i) {
  // 1<<i will create a number with ith bit set to 1 and all other bits set to
  // 0.
  int mask = 1 << i;
  // If we do a bitwise AND with n, we will get 0 if ith bit is 0 and 1 if ith
  // bit is 1.
  return (n & mask) ? 1 : 0;
}

void setIthBit(int &n, int i) {
  // 1<<i will create a number with ith bit set to 1 and all other bits set to
  // 0.
  int mask = 1 << i;
  // If we do a bitwise OR with n, we will set the ith bit to 1.
  n = n | mask;
}

void clearIthBit(int &n, int i) {
  // ~(1<<i) will create a number with ith bit set to 0 and all other bits set
  // to 1.
  int mask = ~(1 << i);
  // If we do a bitwise AND with n, we will set the ith bit to 0.
  n = n & mask;
}

void updateIthBit(int &n, int i, int v) {
  // Clear the ith bit.
  clearIthBit(n, i);
  // Set the ith bit to v.
  int mask = v << i;
  // If we do a bitwise OR with n, we will set the ith bit to v.
  n = n | mask;
}

void clearLastIBits(int &n, int i) {
  // -1 will create a number with all bits set to 1. If we shift it i times to
  // the left, we will get a number with the last i bits set to 0 and all other
  // bits set to 1.
  int mask = -1 << i;
  // If we do a bitwise AND with n, we will set the last i bits to 0.
  n = n & mask;
}

void clearBitsInRange(int &n, int i, int j) {
  // -1 will create a number with all bits set to 1. If we shift it j + 1 times
  // to the left, we will get a number with the last j + 1 bits set to 0 and all
  // other bits set to 1.
  int a = -1 << (j + 1);
  // If we shift 1 i times to the left, we will get a number with the the ith
  // bit set to 1 and all other bits set to 0. If we subtract 1 from it, we
  // will get a number with the first i-1 bits set to 1 and all other bits set
  // to 0.
  int b = (1 << i) - 1;
  // If we do a bitwise OR with a and b, we will get a number with the bits from
  // i to j set to 0 and all other bits set to 1.
  int mask = (a | b);
  // If we do a bitwise AND with n, we will set the bits from i to j to 0.
  n = n & mask;
}

int main() {
  int n;
  cin >> n;
  int i;
  cin >> i;
  int v;
  cin >> v;
  // cout << getIthBit(n, i) << endl;
  // setIthBit(n, i);
  // clearIthBit(n, i);
  // updateIthBit(n, i, v);
  clearLastIBits(n, i);
  cout << n << endl;
  return 0;
}
