#include <iostream>

using namespace std;

bool isPowerOf2(int n){
  // If n is a power of 2, then n & (n-1) will be 0.
  // because n will have only 1 bit set to 1 and n-1 will have all bits set to 1
  // subtracting 1 from n will make the rightmost 1 bit to 0 and all the bits to the right of it to 1
  return (n & (n-1)) == 0;
}

int main() {
  int n;
  cin>>n;
  if(isPowerOf2(n))
    cout<<"Yes, "<< n<< " is a power of 2."<<endl;
  else
    cout<<"No, "<< n<< " is not a power of 2."<<endl;
  return 0;
}
