#include <bits/stdc++.h>
using namespace std;

long long int powerModulo(int a, int b) {
  if (b == 0) {
    return 1;
  }
  long long half = powerModulo(a, b / 2);
  long long ans = (half * half) % 1000000007;

  if (b % 2 == 1) {
    ans = (ans * a) % 1000000007;
  }

  return ans;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << powerModulo(a, b) << endl;
  return 0;
}
