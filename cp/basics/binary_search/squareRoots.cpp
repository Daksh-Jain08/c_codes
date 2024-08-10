#include <iostream>

using namespace std;

// Problem: Given an integer k, find the square root of k to 3 decimal places.

// Approach: We will use binary search to find the integer part of the square
// root of k. We will then find the decimal part of the square root of k by
// checking the values from 0.1 to 0.0001. We will add the decimal part to the
// integer part to get the square root of k to 3 decimal places.

int squareRootInt(int k) {
  int root = 0;
  int start = 1, end = k;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (mid * mid < k) {
      root = mid;
      start = mid + 1;
    } else
      end = mid - 1;
  }
  return root;
}

double squareRoot(int k) {
  double root = double(squareRootInt(k));
  if (root * root == k)
    return root;

  double pow = 0.1;
  for (int i = 0; i < 3; i++) {
    double j = 1 * pow;
    for (; j <= pow * 9; j += pow) {
      double val = root + j;
      if (val * val > k) {
        j -= pow;
        break;
      }
    }
    root += j;
    pow /= 10;
  }
  return root;
}

int main() {
  int k;
  cin >> k;
  cout << squareRoot(k) << endl;
  return 0;
}
