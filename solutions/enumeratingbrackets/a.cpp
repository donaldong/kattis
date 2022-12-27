/**
 * @date        2022-12-26
 * @tags        dp
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using lll = __int128;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  ll m;
  cin >> n >> m;
  vector<vector<lll>> DP(n, vector<lll>(n+1, -1));

  function<lll(int,int)> dfs = [&](int i, int v) -> lll {
    if (i == n && v == 0) return 1;
    if (i >= n || v < 0) return 0;
    auto& res = DP[i][v];
    if (res != -1) return res;
    res = dfs(i+1, v+1) + dfs(i+1, v-1);
    if (res >= ULLONG_MAX) res = ULLONG_MAX; // clip max
    return res;
  };

  string res = "(";
  for (int i = 1, v = 1; i < n; ++i) {
    auto a = dfs(i+1, v+1);
    if (a >= m) res += '(', ++v;
    else res += ')', --v, m -= a;
  }
  cout << res << endl;
  return 0;
}
