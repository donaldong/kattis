#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(ll n, ll k) {
  ll a = 2 * n - k * k - k;
  ll b = 2 * k + 2;
  if (a % b) return 0;
  return a / b;
}

void solve(int n, ll &k, int &a) {
  int t;
  for (k = 1; k * k + k < 2 * n; ++k) {
    a = solve(n, k);
    if (a > 0) return;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n, a;
  ll k;
  cin >> t;
  while (t--) {
    cin >> n;
    a = 0, solve(n, k, a);
    if (!a) printf("IMPOSSIBLE\n");
    else {
      printf("%d = %d", n, a++);
      for (int i = 0; i < k; ++i, ++a) printf(" + %d", a);
      printf("\n");
    }
  }
  return 0;
}
