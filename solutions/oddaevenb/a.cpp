/**
 * @author      Donald Dong
 * @date        2022-03-21
 * @tags        dp, combinatorics
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
vector<vector<int>> DP;
int dfs(int n, int d) {
  if (n == 0) return 1;
  if (n == 1) return d == 0;
  if (n == 2) return d == 1;
  auto& res = DP[n][d];
  if (res>=0) return res;
  int tot = 0;
  for (int i = n-d-1; i >= 0; i -= 2) {
    tot = (tot+dfs(i, 1-d))%MOD;
  }
  return res = tot;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0); // Fast IO
  int N;
  cin >> N;
  DP.assign(N+1, vector<int>(2, -1));
  cout << (dfs(N,0)+dfs(N,1))%MOD << endl;
}
