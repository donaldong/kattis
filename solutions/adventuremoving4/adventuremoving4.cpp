#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll INF = 1e17;
using vi = vector<ll>;
using v2i = vector<vi>;
int MAX_LITRE = 201;

#ifdef DEBUG
void debug(v2i &G) {
  for (auto &row : G) {
    for (auto cell : row) if (cell == INF) cout << "I ";
    else cout << cell << " ";
    cout << endl;
    cout << endl;
  }
}
#endif

int main() {
  int target, d, p;
  vi D = {0}, P = {0};
  cin >> target;
  while (cin >> d >> p) {
    D.push_back(d), P.push_back(p);
  }
  v2i DP(D.size(), vi(MAX_LITRE, INF));
  for (int i = 0; i <= 100; ++i) DP[0][i] = 0;
  for (size_t s = 1; s < D.size(); ++s) {
    ll d = D[s] - D[s - 1];
    for (int prev = d; prev < MAX_LITRE; ++prev) {
      if (DP[s - 1][prev] == INF) continue;
      ll remain = prev - d;
      for (int cur = remain; cur < MAX_LITRE; ++cur) {
        ll added = cur - remain;
        DP[s][cur] = min(DP[s][cur], DP[s - 1][prev] + P[s] * added);
      }
    }
#ifdef DEBUG
  debug(DP);
#endif
  }
  ll res = INF;
  for (ll i = target - D.back() + 100; i < MAX_LITRE; ++i) {
    res = min(res, DP.back()[i]);
  }
  if (res == INF) cout << "Impossible" << endl;
  else cout << res << endl;
  return 0;
}
