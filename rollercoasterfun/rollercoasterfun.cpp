#include <bits/stdc++.h>
using namespace std;

int MAX_T = 25001;
int MAX_N = 101;

using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
using ll = long long;
using vi = vector<int>;
using v2i = vector<vi>;

v2i M(MAX_N, vi(MAX_T, -1));

ll calc(int a, int b, int k) {
  ll r = k - 1;
  return a - r * r * b;
}

ll solve(vti3 &N, int k, int t) {
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
    cin >> t;
    cout << solve(N, N.size() - 1, t) << endl;
  }
  return 0;
}
