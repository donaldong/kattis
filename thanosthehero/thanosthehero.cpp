#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
vi N;

ll solve() {
  ll res = 0;
  for (size_t i = N.size() - 1; i-- > 0;) {
    ll lim = N[i + 1] - 1;
    if (lim < 0) return 1;
    if (N[i] > lim) {
      res += N[i] - lim;
      N[i] = lim;
    }
#ifdef DEBUG
    printf("%zu lim: %lld, cur: %d\n", i, lim, N[i]);
#endif
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  N.resize(n);
  for (int i = 0; i < n; ++i) cin >> N[i];
  printf("%lld\n", solve());
  return 0;
}
