#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll l, ll r) {
  ll h = l + r + 1;
  return h * (h + 1) / 2 - l;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    cout << solve(l, r) << endl;
  }
  return 0;
}
