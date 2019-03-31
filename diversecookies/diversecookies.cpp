#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sort(ll &a, ll &b, ll &c) {
  if (a > c) swap(a, c);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  ll res = 0, m;
  sort(a, b, c);
  if (a + b < c) {
    m = a + b;
    c -= m, res += 2 * a + 2 * b;
    res += min(n, c);
  } else res = a + b + c;
  printf("%lld\n", res);
  return 0;
}
