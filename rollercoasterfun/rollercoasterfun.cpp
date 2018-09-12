#include <bits/stdc++.h>
using namespace std;

int MAX_T = 25001;
int MAX_N = 101;
int MAX_K = 40;

using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
using ll = long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;

v3i M(MAX_N, v2i(MAX_T, vi(MAX_K, -1)));

ll calc(int a, int b, int k) {
  ll r = k - 1;
  return a - r * r * b;
}

ll solve(vti3 &N, int n, int t, int k) {
  if (k < 0 || t <= 0) return 0;
  if (M[k][t] != -1) return M[k][t];
  int a, b, c, s = 1, sum = 0;
  tie(a, b, c) = N[k];
  int cur = c;
  ll res = solve(N, k - 1, t);
  while (cur <= t) {
    sum += calc(a, b, s);
    ll r = solve(N, k - 1, t - cur) + sum;
    if (r <= res) break;
    res = r;
    ++s;
    cur += c;
  }
  M[k][t] = res;
  return res;
}

int main() {
  int n, a, b, t, q;
  cin >> n;
  vti3 N(n);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> t;
    N[i] = make_tuple(a, b, t);
  }
  cin >> q;
  while (q--) {
    int t2;
    cin >> t2;
    ll res = 0;
    int k = t2 / t;
    for (int i = 0; i <= k; ++i) {
      res = max(res, solve(N, N.size() - 1, t2, i));
      cout << res << endl;
    }
  }
  return 0;
}
