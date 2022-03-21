#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
int INF = 1e8, MAX_NUM = 1e5;

vi solve(vi &V) {
  v2i DP(2, vi(MAX_NUM + 1, INF));
  DP[0][0] = 0;
  for (int i = 0; i < V.size(); ++i) {
    for (int j = 0; j <= MAX_NUM; ++j) {
      DP[1][j] = DP[0][j];
      if (j >= V[i]) DP[1][j] = min(DP[1][j], DP[0][j - V[i]] + 1);
    }
    swap(DP[0], DP[1]);
  }
  return DP[0];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  vi H, B;
  int h, b;
  cin >> h, H.resize(h);
  for (auto &e : H) cin >> e;
  cin >> b, B.resize(b);
  for (auto &e : B) cin >> e;
  vi DP_H = solve(H), DP_B = solve(B);
  int res = INF;
  for (int i = 1; i <= MAX_NUM; ++i) res = min(res, DP_H[i] + DP_B[i]);
  if (res >= INF) printf("impossible\n");
  else printf("%d\n", res);
  return 0;
}
