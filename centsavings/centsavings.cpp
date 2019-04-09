#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int N, D, INF = 1e9;
vi P, SUM;
v2i DP;

int calc(int a, int b) {
  int res = SUM[b] - (a ? SUM[a - 1] : 0);
  int r = res / 10;
  if (res % 10 >= 5) ++r;
  return 10 * r;
}

int solve(int n, int d) {
  if (DP[n][d] != INF) return DP[n][d];
  int res = calc(0, n);
  if (n < d) res = solve(n, n);
  else if (d >= 1) for (int i = d - 1; i < n; ++i) {
    res = min(res, solve(i, d - 1) + calc(i + 1, n));
  }
  DP[n][d] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N >> D;
  DP.assign(N, vi(D + 1, INF));
  P.resize(N), SUM.resize(N);
  for (auto &e : P) cin >> e;
  SUM[0] = P[0];
  for (int i = 1; i < N; ++i) SUM[i] = P[i] + SUM[i - 1];
  printf("%d\n", solve(N - 1, D));
  return 0;
}
