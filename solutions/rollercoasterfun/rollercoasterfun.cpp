#include <bits/stdc++.h>
using namespace std;

int MAX_T = 25001;
int MAX_N = 101;

using ti3 = tuple<int, int, int>;
using vti3 = vector<ti3>;
using ll = long long;
using vi = vector<ll>;
using v2i = vector<vi>;

v2i M(MAX_N, vi(MAX_T, 0));

ll calc(ll a, ll b, ll k) {
  ll r = k - 1;
  return a - r * r * b;
}

void fill(vti3 &N) {
  int a, b, c, _n = N.size();
  for (int n = 1; n <= _n; ++n) {
    tie(a, b, c) = N[n - 1];
    vi S(36, 0);
    size_t k = 1;
    for (; k < S.size(); ++k) {
      ll r = calc(a, b, k);
      if (r <= 0) break;
      S[k] = S[k - 1] + r;
    }
    for (int t = 1; t < MAX_T; ++t) {
      ll res = M[n - 1][t];
      if (!b) {
        if (t - c >= 0) res = max(
          res,
          M[n][t - c] + a
        );
      } else {
        for (size_t i = 1; i < k; ++i) {
          int r = t - i * c;
          if (r >= 0) res = max(res, M[n - 1][r] + S[i]);
          else break;
        }
      }
      M[n][t] = max(res, M[n][t - 1]);
    }
  }
}

int main() {
  int n, a, b, t, q;
  cin >> n;
  vti3 N(n);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> t;
    N[i] = make_tuple(a, b, t);
  }
  fill(N);
  cin >> q;
  while (q--) {
    cin >> t;
    cout << M[n][t] << endl;
  }
  return 0;
}

