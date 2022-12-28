/**
 * @date        2022-12-28
 * @tags        dp
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  string s;
  int mod = 1e6;
  vector<vector<int>> DP(1001, vector<int>(1001, 0));
  while (cin >> s) {
    int n = s.size();
    for (int i = 0; i <= n; ++i) fill(DP[i].begin(), DP[i].end(), 0);
    DP[n][0] = 1;
    for (int i = n-1; i >= 0; --i) {
      for (int j = 0; j < n; ++j) {
        auto& v = DP[i][j];
        switch (s[i]) {
          case '(': v = DP[i+1][j+1]; break;
          case ')': if (j) v = DP[i+1][j-1]; break;
          case '.': {
            v = DP[i+1][j+1];
            if (j) v += DP[i+1][j-1];
            v %= mod;
            break;
          }
        }
      }
    }
    cout << DP[0][0] << '\n';
  }
  return 0;
}
