#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> v2ll;
int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  v2ll DP(n + 1, vll(k + 1, 0));
  DP[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      ll t = DP[i - 1][j - 1] * j + DP[i - 1][j] * (j - 1);
      DP[i][j] = t % MOD;
    }
  }
  printf("%lld\n", DP[n][k]);
  return 0;
}
