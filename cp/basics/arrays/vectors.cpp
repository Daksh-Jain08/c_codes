#include <iostream>
#include <vector>

using namespace std;

int main() {
  // vector<int> v = {1, 2, 5, 10, 12};

  // fill constructor vector<type> v(size, element)
  vector<int> v(10, 7);

  // push_back() (inserts an element at the end of the vector in O(1) time.
  v.push_back(20);

  // printing all the elements in the array.
  /*for (int i = 0; i < v.size(); i++)
    cout << v[i] << ", ";
  cout << endl;*/

  for (int x : v)
    cout << x << ", ";
  cout << endl;

  /*
  // Size of the vector (Number of elements in the vector)
  cout << v.size() << endl;

  // Capacity of vector
  cout << v.capacity() << endl;
  */

  // 2d vectors
  vector<vector<int>> arr = {
      {1, 2, 4},
      {6, 21, 9},
      {4, 7, 12, 23},
      {10},
  };

  for (int i = 0; i < arr.size(); i++) {
    for (int number : arr[i])
      cout << number << ", ";
    cout << endl;
  }

  return 0;
}
