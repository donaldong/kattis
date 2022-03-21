#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
int INF = 1e9;

#ifdef DEBUG
void debug(v2i &G) {
  for (auto &row : G) {
    for (auto cell : row) {
      if (cell == INF) cout << "I ";
      else cout << cell << " ";
    }
    cout << endl;
  }
}
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, target, n;
  cin >> t;
  while (t--) {
    cin >> target >> n;
    vi C(n + 1);
    C[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> C[i];
    int MAX_PAYMENT = target + 1e4 + 1;
    v2i DP(n + 1, vi(MAX_PAYMENT, INF));
    for (int i = 0; i <= n; ++i) DP[i][0] = 0;
    int min_payment = INF, res = INF;
    for (int p = 1; p < MAX_PAYMENT; ++p) {
      for (int c = 1; c <= n; ++c) {
        int remain = p - C[c];
        DP[c][p] = min(DP[c][p], DP[c - 1][p]);
        if (remain >= 0 && DP[c - 1][remain] != INF)
          DP[c][p] = min(DP[c][p], DP[c - 1][remain] + 1);
        if (DP[c][p] == INF) continue;
        if (target <= p && p < min_payment) {
          min_payment = p;
          res = DP[c][p];
        } else if (target <= p && p == min_payment) {
          res = min(res, DP[c][p]);
        }
      }
    }
    cout << min_payment << " " << res << endl;
  }
  return 0;
}
