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
#define set_vector(v, s)                                                       \
  for (auto x : v)                                                             \
    s.insert(x);

using namespace std;

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> color(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (color[i] == 0) {
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
          int node = q.front();
          q.pop();
          for (int neighbor : graph[node]) {
            if (color[neighbor] == 0) {
              color[neighbor] = -color[node];
              q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution *s = new Solution();
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  vector<vector<string>> ans = s->ladderLength(beginWord, endWord, wordList);
  for (auto v : ans) {
    printvec(v);
  }

  return 0;
}
