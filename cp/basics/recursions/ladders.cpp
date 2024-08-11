#include<iostream>

using namespace std;

// Problem: Given a ladder of n steps, find the number of ways to reach the top by taking 1, 2 or 3 steps at a time.

// Approach: At each step, we have 3 choices. We can take 1, 2 or 3 steps. So, we can write the recursive function as:
// ladders(n) = ladders(n-1) + ladders(n-2) + ladders(n-3)


int ladders(int n){
  // Base cases
  if(n <= 0)
    return 0;
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;
  if(n == 3)
    return 3;

  // Recursive case
  return ladders(n-1) + ladders(n-2) + ladders(n-3);
}

int main(){
  int n = 5;
  cout<<ladders(n);
  return 0;
}

