#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
int MOD = 1e6;

int main() {
  vll res(MOD + 1);
  res[0] = res[1] = 1;
  for (ll i = 2; i < MOD; ++i) {
    ll k = res[i - 1] * i;
    while (k % 10 == 0) k /= 10;
    k %= MOD;
    res[i] = k;
  }
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    if (!n) break;
    cout << res[n] % 10 << endl;
  }
  return 0;
}
