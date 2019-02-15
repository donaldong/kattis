#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
int M, K;
vi DP, V;
int INF = 2e6;

int sum(int s) {
  int i = 0, res = 0;
  while (s) {
    if (s & 1) res += V[i];
    ++i;
    s >>= 1;
  }
  return res;
}

int solve(int s) {
  if (DP[s] != INF) return DP[s];
  int res = 0;
  for (int i = 0; i < M; ++i) {
    int b = 1 << i;
    if (!(s & b)) continue;
    int ns = s ^ b;
    if (ns) res = max(res, solve(ns));
  }
  if (sum(s) == 0) ++res;
  DP[s] = res;
#ifdef DEBUG
  printf("DP[%d] = %d\n", s, res);
#endif
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b, p;
  cin >> M >> n;

  V.assign(M, 0);
  DP.assign(1 << M, INF);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> p;
    V[a] -= p, V[b] += p;
  }

  printf("%d\n", M - solve((1 << M) - 1));
  return 0;
}
