#include <climits>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> sortSubArray(vector<int> v){
  pair<int,int> ans = {-1, -1};
  int n = v.size();
  int highest_unsorted = INT_MIN;
  int lowest_unsorted = INT_MAX;
  if(n>1 and v[0]>v[1])
    highest_unsorted = lowest_unsorted = v[0];

  for(int i = 1; i < n - 1; i++){
    if(v[i]<v[i-1] or v[i]>v[i+1]){
      highest_unsorted = max(highest_unsorted, v[i]);
      lowest_unsorted = min(lowest_unsorted, v[i]);
    }
  }

  if(n>1 and v[n-1]<v[n-2]){
    cout<<"here"<<endl;
    highest_unsorted = max(highest_unsorted, v[n]);
    lowest_unsorted = min(lowest_unsorted, v[n]);
  }

  int j = 0, k = n-1;
  while(v[j]<=lowest_unsorted)
    j++;
  while(v[k]>=highest_unsorted)
    k--;
  if(lowest_unsorted!=INT_MAX){
    ans.first = j;
    ans.second = k;
  }
  return ans;
}

int main() {
  vector<int> v = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
  pair<int, int> ans = sortSubArray(v);
  cout<<ans.first<<" "<<ans.second<<endl;
  return 0;
}
