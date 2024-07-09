#include<iostream>
#include<vector>
using namespace std;

//Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.

vector<int> productArray(vector<int> arr){
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    vector<int> prefix(n,1), suffix(n,1);
    
    for(int i = 1; i<n;i++){
        prefix[i] = prefix[i-1]*arr[i-1];
        suffix[n-i-1] = suffix[n-i]*arr[n-i];
    }
    
    for(int i = 0; i<n; i++){
        output[i] = prefix[i]*suffix[i];
    }
    
    
    return output;
}

int main() {
  vector<int> v = {1,2,3,4,5};
  vector<int> ans = productArray(v);
  for(int x : ans)
    cout<<x<<",";
  cout<<endl;
  return 0;
}
