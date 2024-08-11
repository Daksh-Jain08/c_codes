#include<iostream>
#include<vector>

using namespace std;

int subArraySum(vector<int> v, int n, int i, int target){
  if(i == n){
    if(target == 0){
      return 1;
    }
    return 0;
  }
  int including = subArraySum(v, n, i+1, target - v[i]);
  int excluding = subArraySum(v, n, i+1, target);
  int subtracting = subArraySum(v, n, i+1, target + v[i]);
  return including + excluding + subtracting;
} 

int main(){
  vector<int> v = {1, 2, 3, 4, 5};
  int n = v.size();
  int target = 10;
  cout<<subArraySum(v, n, 0, target);
  return 0;
}
