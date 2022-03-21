#include <bits/stdc++.h>
using namespace std;
unordered_map<char,unordered_map<char,int>> G;

int dfs(char u, int n) {
  int res = 1;
  for (auto [v, f] : G[u]) {
    if (f != n) continue;
    res = max(res, dfs(v, n)+1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;

  for (int t = 0; t < n; ++t) {
    cin >> s;
    for (int i = 0; i < k; ++i) {
      for (int j = i+1; j < k; ++j) {
        ++G[s[i]][s[j]];
      }
    }
  }
  int res = 0;
  for (int i = 0; i < k; ++i) {
    res = max(res, dfs('A'+i, n));
  }
  cout << res << endl;
  return 0;
}
