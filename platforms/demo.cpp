#include <bits/stdc++.h>
#include <climits>
#include <csignal>

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
void solve() {
  ll n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  forr(i, 0, n) forr(j, 0, n) cin >> v[i][j];

  vector<ll> ones(n, 0);
  forr(i, 0, n) {
    for (ll j = n - 1; j >= 0; j--) {
      if (v[i][j] == 1) {
        ones[i]++;
      } else {
        break;
      }
    }
  }
  sort(ones.begin(), ones.end());
  ll counter = 0;
  for(ll i : ones)
    counter += (i >= counter);
  cout << counter << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
