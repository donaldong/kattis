#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi P, T;

int dfs(int n, int c) {
  if (T[n] > 0) return T[n];
  if (T[n] == 0) return c;
  T[n] = 0;
  return T[n] = dfs(P[n], c + 1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, c, d;
  ll a, b;
  cin >> n >> a >> b >> c >> d;
  P.resize(n + 1), T.assign(n + 1, -1);
  for (int i = 1; i <= n; ++i) cin >> P[i];
  ll k = 1;
  for (int i = c + 1; i <= n - d; ++i) {
    dfs(i, 0);
    k = lcm(k, T[i]);
  }
  ll res = b / k;
  if (b % k) ++res;
  --a, res -= a / k;
  if (a % k) --res;
#ifdef DEBUG
  printf("a=%lld, b=%lld, k=%lld\n", a, b, k);
#endif
  printf("%lld\n", res);
  return 0;
}
