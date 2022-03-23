/**
 * @date        2022-03-22
 * @tags        grid, shortest path, dp
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N, K;
  cin >> N >> K;
  vector<vector<pair<int,int>>> P(K+1);
  for (int r = 0; r < N; ++r) for (int c = 0, k; c < N; ++c) {
    cin >> k;
    P[k].emplace_back(r, c);
  }
  ll res = LLONG_MAX, dr, dc, dist;
  vector<ll> R1(N, 0), C1(N, 0);
  for (int i = 1; i <= K; ++i) {
    vector<ll> R2(N, LLONG_MAX), C2(N, LLONG_MAX);
    for (auto [r1, c1] : P[i]) {
      dist = min(R1[r1], C1[c1]);
      if (dist == LLONG_MAX) continue;
      if (i == K) res = min(res, dist);
      for (int r2 = 0; r2 < N; ++r2) dr = r2-r1, R2[r2] = min(R2[r2], dist+dr*dr);
      for (int c2 = 0; c2 < N; ++c2) dc = c2-c1, C2[c2] = min(C2[c2], dist+dc*dc);
    }
    swap(R1, R2), swap(C1, C2);
  }
  cout << (res == LLONG_MAX ? -1 : res) << endl;
  return 0;
}
