#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N, x, y;
  cin >> N;
  int K = N * 10;
  ll res = 0;
  v3i DP(2, v2i(2 * K + 1, vi(2 * K + 1, 0)));
  DP[0][K][K] = 1;

  while (N--) {
    cin >> x >> y;
    for (int x1 = -K; x1 <= K; ++x1) {
      for (int y1 = -K; y1 <= K; ++y1) {
        if (!DP[0][x1 + K][y1 + K]) continue;
        DP[1][x1 + K][y1 + K] += DP[0][x1 + K][y1 + K];
        int x2 = x1 + x, y2 = y1 + y;
        if (x2 < -K || y2 < -K || x2 > K || y2 >= K) continue;
        DP[1][x2 + K][y2 + K] += DP[0][x1 + K][y1 + K];
      }
    }
    DP[0] = DP[1];
    DP[1] = v2i(2 * K + 1, vi(2 * K + 1, 0));
  }

  printf("%lld\n", DP[0][K][K] - 1);
  return 0;
}
