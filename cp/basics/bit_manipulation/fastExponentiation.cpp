#include <iostream>

using namespace std;

int fastExponentiation(int a, int n) {
  int ans = 1;
  while (n > 0) {
    int last_bit = (n & 1);
    // If the last bit of n is 1, multiply ans with a.
    if (last_bit)
      ans = ans * a;
    // Square a and divide n by 2.
    a = a * a;
    n = n >> 1;
  }
  return ans;
}

int main() {
  int a, n;
  cin >> a >> n;
  int ans = fastExponentiation(a, n);
  cout << ans << endl;
  return 0;
}
