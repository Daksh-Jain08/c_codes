#include <iostream>

using namespace std;

// The Planet Earth is under a threat from the aliens of the outer space and
// your task is to defeat an enemy who is N steps above you (assume yourself to
// be at ground level i.e. at the 0th level). You can take jumps in power of 2.
// In order to defeat the enemy as quickly as possible you have to reach the Nth
// step in minimum moves possible.

int minimumSteps(int n) {
  int count = 0;
  while (n > 0) {
    // count the number of set bits in n.
    n = n & n - 1;
    count++;
  }
  return count;
}

// The minimum number of steps required to reach the Nth step is equal to the number of set bits in N.

int main() {
  int n;
  cin >> n;
  cout << minimumSteps(n) << endl;
  return 0;
}
