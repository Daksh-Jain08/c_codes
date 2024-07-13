#include <iostream>
using namespace std;

int main() {
  int m;
  cin >> m;
  if (!(m & 1)) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }

  return 0;
}
