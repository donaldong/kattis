#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using v2i = vector<vi>;
ll NEG_INF = -1e14;
v2i MSA;
vi N;

int split_point(int a, int b) {
  ll max_sum = NEG_INF;
  int p;
  for (int i = a; i < b; ++i) {
    ll s = MSA[a][i] + MSA[i + 1][b];
    if (s > max_sum) max_sum = s, p = i;
  }
  return p;
}

ll delta(int a, int b, int &p) {
  p = split_point(a, b);
  return MSA[a][p] + MSA[p + 1][b] - MSA[a][b];
}

ll solve(int a, int b, int k) {
  int p, p1, p2;
  ll res = MSA[a][b], s, d, d1, d2;
  if (k == 1) return res;
  priority_queue<tuple<ll, int, int, int>> Q;
  d = delta(a, b, p);
  Q.emplace(d, a, b, p);
  for (--k; k-- > 0;) {
    tie(d, a, b, p) = Q.top(), Q.pop();
#ifdef DEBUG
    printf("%d: <%lld> %d %d | %d\n", k, d, a, b, p);
#endif
    res += d;
    if (a < p) {
      d1 = delta(a, p, p1);
      Q.emplace(d1, a, p, p1);
    }
    if (p + 1 < b) {
      d2 = delta(p + 1, b, p2);
      Q.emplace(d2, p + 1, b, p2);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;

  N.resize(n);
  MSA.assign(n, vi(n));
  for (int i = 0; i < n; ++i) cin >> N[i];
  for (int i = 0; i < n; ++i) {
    ll tot = 0, res = NEG_INF;
    for (int j = i; j < n; ++j) {
      if (tot < 0) tot = 0;
      tot += N[j];
      res = max(res, tot);
      MSA[i][j] = res;
    }
  }

  printf("%lld\n", solve(0, n - 1, k));
  return 0;
}
