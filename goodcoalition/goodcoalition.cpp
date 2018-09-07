#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using vld = vector<ld>;
using v2ld = vector<vld>;
using vi = vector<int>;

int MAX_SUM = 151;

v2ld M;

ld solve(vi &S, vld &P, int n, int sum) {
  if (n < 0 || sum < 0) return 0;
  if (M[n][sum] > -0.5) return M[n][sum];
  ld res = solve(S, P, n - 1, sum);
  if (sum == S[n]) res = max(res, P[n]);
  else res = max(res, solve(S, P, n - 1, sum - S[n]) * P[n]);
  M[n][sum] = res;
  return res;
}

ld solve(vi &S, vld &P) {
  ld res = -1;
  for (int i = 76; i < MAX_SUM; ++i) {
    res = max(res, solve(S, P, S.size() - 1, i));
  }
  return res;
}

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vi S(n);
    vld P(n);
    M = v2ld(n, vld(MAX_SUM, -1));
    for (int i = 0; i < n; ++i) {
      cin >> S[i] >> P[i];
      P[i] /= 100.0;
    }
    printf("%.7Lf\n", solve(S, P) * 100.0);
  }
  return 0;
}
