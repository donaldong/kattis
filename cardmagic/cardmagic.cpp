#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using v2ll = vector<vll>;

ll MOD = 1e9 + 9;
v2ll M;

int K;

ll solve(int n, int t) {
  if (n <= 0 || t <= 0) return 0;
  if (n == 1) return t <= K;
  if (M[n][t] >= 0) return M[n][t];
  ll res = 0;
  for (int k = 1; k <= min(K, t); ++k) {
    res = (res + solve(n - 1, t - k)) % MOD;
  }
  M[n][t] = res;
  return res;
}

int main() {
  int n, t;
  cin >> n >> K >> t;
  M = v2ll(n + 1, vll(t + 1, -1));
  cout << solve(n, t) << endl;
  return 0;
}
