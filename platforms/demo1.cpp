#include <bits/stdc++.h>
#include <climits>

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vvs vector<vector<string>>
#define vs vector<string>
#define all(x) x.begin(), x.end()
#define forr(i, a, b) for (int i = a; i < b; i++)
#define print(x, seperator) cout << x << seperator;
#define printvec(v)                                                            \
  for (auto x : v)                                                             \
    cout << x << " ";                                                          \
  cout << endl;
#define forvec(x, v) for (auto x : v)
#define dbg(x) cout << #x << " = " << x << endl;
#define pii pair<int, int>
#define ia(a, n)                                                               \
  for (int i = 0; i < n; i++)                                                  \
    cin >> a[i];

using namespace std;

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i])
        cnt++;
    }
    if (cnt == 0)
      return true;
    if (cnt == 2) {
      for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
          for (int j = i + 1; j < n; j++) {
            if (s1[j] != s2[j]) {
              if (s1[i] == s2[j] && s1[j] == s2[i])
                return true;
            }
          }
        }
      }
    }
    return false;
  }
};

// Main function
int main() {
  Solution sol;
  string s1 = "bank", s2 = "kanb";
  cout << sol.areAlmostEqual(s1, s2) << endl;
  return 0;
}
