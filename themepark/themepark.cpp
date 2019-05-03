#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> v2i;

ll sum(vi &N, int i, int j) {
  ll res = 0;
  for (i = i % N.size(); j; i = (i + 1) % N.size(), --j) res += N[i];
  return res;
}

ll solve(int k, vi &N, int &runs, vi &L, int &cycle_start) {
  ll res = 0;
  v2i C(N.size(), vi(N.size() + 1, -1));
  for (int i = 0, r = 0; runs;) {
    int j = 0;
    ll tot = 0;
    for (; j < N.size(); ++j) {
      int v = N[(i + j) % N.size()];
      if (tot + v > k) break;
      else tot += v;
    }
    if (C[i][j] >= 0) { cycle_start = C[i][j]; return res; }
    L.push_back(j);
    C[i][j] = r, i = (i + j) % N.size();
    res += tot, ++r, --runs;
  }
  return res;
}

int main() {
  int T, r, k, n;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> r >> k >> n;
    int cycle_start;
    vi N(n), L;
    for (auto &e : N) cin >> e;
    ll cycle_sum = 0, tot = solve(k, N, r, L, cycle_start);
    if (r) {
      vector<ll> sums(L.size());
      int cycle_length = L.size() - cycle_start;
      for (int i = 0, j = 0; i < L.size(); j += L[i], ++i) {
        if (i >= cycle_start) sums[i] = sum(N, j, L[i]), cycle_sum += sums[i];
      }
      ll x = r / cycle_length;
      tot += cycle_sum * x;
      for (int i = 0, j = r % cycle_length; j--; ++i) tot += sums[cycle_start + i];
    }
    printf("Case #%d: %lld\n", t, tot);
  }
  return 0;
}
