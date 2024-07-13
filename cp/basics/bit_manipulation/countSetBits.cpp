#include<iostream>

using namespace std;

//This method is the most efficient way to count the number of set bits in a number.
int countSetBits(int n){
  int count = 0;
  while(n){
    // If we do a bitwise AND with n and n-1, we will clear the rightmost set bit.
    n = n & (n-1);
    count++;
  }
  return count;
}

int countSetBits1(int n){
  int count = 0;
  while(n){
    // If we do a bitwise AND with n and 1, we will get the rightmost bit.
    int last_bit = n & 1;
    // If the rightmost bit is 1, increment the count.
    count += last_bit;
    // If we shift n to the right by 1, the rightmost bit will be removed.
    n = n >> 1;
  }
  return count;
}

int main() {
  int n;
  cin>>n;
  cout<<countSetBits(n)<<endl;
  return 0;
}
