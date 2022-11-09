/**
 * @date        2022-11-08
 * @tags        dp
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  string p, s;
  cin >> p >> s;
  int res = 0, MOD = 1e9+7, len = s.size();
  unordered_set<string> vis;
  vector<int> dp(p.size()+1, 0), dpPrev(p.size()+1, 0);
  for (int r = 0; r < len; ++r) {
    string s2 = s.substr(r) + s.substr(0, r);
    if (vis.count(s2)) continue;
    vis.insert(s2);
    for (int j = len-1; j >= 0; --j) {
      for (int i = p.size()-1; i >= 0; --i) {
        if (p[i] == s2[j]) {
          if (j == len-1) {
            dp[i] = (1+dp[i+1])%MOD;
          } else {
            dp[i] = (dpPrev[i+1]+dp[i+1])%MOD;
          }
        } else dp[i] = dp[i+1];
      }
      swap(dp, dpPrev);
    }
    res = (res+dpPrev[0])%MOD;
  }
  cout << res << endl;
  return 0;
}

