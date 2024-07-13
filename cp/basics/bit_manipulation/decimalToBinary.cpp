#include <iostream>

using namespace std;

// This function will convert a decimal number to a binary number.
// For example, if n = 13, the binary representation of 13 is 1101.
// So, the function will check the last bit, that is 1 and multiply it with 1,
// then add it to the answer. Then it will perform a right shift to make the
// second last bit the last bit. It will also p by 10 to multiply the next bit
// with 10. It will continue this process until n becomes 0.
int decimalToBinary(int n) {
  int ans = 0;
  int p = 1;
  while (n > 0) {
    // Get the last bit of n.
    int last_bit = (n & 1);
    // Multiply the last bit with the power of 10 and add it to the answer.
    ans += p * last_bit;
    // Multiply p by 10.
    p *= 10;
    // Shift n to the right by 1.
    n = n >> 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int ans = decimalToBinary(n);
  cout << ans << endl;
  return 0;
}
