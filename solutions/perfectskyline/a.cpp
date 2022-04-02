/**
 * @date        2022-04-01
 * @tags        dp, bit mask
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> N,S;
vector<vector<int>> DP;

int dfs(int mask, int s, int v) {
  auto& res = DP[mask][s];
  if (res >= 0) return res;
  if (v > S[s]) return res = 0;
  if (v == S[s]) {
    if (s+1 == S.size() || dfs(mask,s+1,0)) return res = mask;
    return res = 0;
  }
  for (int b = 1, i = 0; i < N.size(); ++i, b <<= 1) {
    if (mask & b) continue;
    auto nextmask = dfs(mask | b, s, v + N[i]);
    if (nextmask) return res = nextmask;
  }
  return res = 0;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, s;
  cin >> n >> s;
  N.resize(n), S.resize(s);
  DP.assign(1<<n, vector<int>(s, -1));
  for (auto& n : N) cin >> n;
  for (auto& s : S) cin >> s;
  int res = dfs(0, 0, 0);
  if (!res) cout << -1 << endl;
  else {
    int mask1 = 0, mask2;
    for (int i = 0; i < s; ++i, mask1 = mask2) {
      mask2 = dfs(mask1, i, 0);
      vector<int> pos;
      for (int b = mask2 ^ mask1, j = 0; b; ++j, b>>=1) {
        if (b&1) pos.push_back(j);
      }
      printf("%lu ", pos.size());
      for (int p : pos) printf("%d ", p+1);
      printf("\n");
    }
  }
  return 0;
}
