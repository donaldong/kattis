#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> tup;

int INF = 1e9;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, n, t, d, a, b;
  cin >> T;
  while (T--) {
    cin >> n >> t;
    vi E(n);
    for (auto &e : E) cin >> e;
    vi DP(3601, INF);
    priority_queue<tup, vector<tup>, greater<tup>> Q;
    Q.emplace(0, 0), DP[0] = 0;
    while (!Q.empty()) {
      tie(d, a) = Q.top(), Q.pop();
      if (d > DP[a]) continue;
      for (int e : E) {
        b = a + e;
        if (b < 0) b = 0;
        if (b >= DP.size()) b = DP.size() - 1;
        if (d + 1 >= DP[b]) continue;
        DP[b] = d + 1, Q.emplace(d + 1, b);
      }
    }
    for (int i = t; i < DP.size(); ++i) {
      if (DP[i] != INF) {
        printf("%d %d\n", DP[i], i - t);
        break;
      }
    }
  }
  return 0;
}
