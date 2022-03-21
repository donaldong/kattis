#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void sort(ll &a, ll &b, ll &c) {
  if (a > c) swap(a, c);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
}

ll calc(ll a, ll b, ll c) {
  return a * a + b * b + c * c + 7 * a;
}

ll solve(ll a, ll b, ll c, ll d) {
  ll res = calc(a, b, c + d);
  while (d && a * 2 + 7 >= 2 * c) {
    ++a, --d;
    sort(a, b, c);
    res = max(res, calc(a, b, c + d));
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  ll a, b, c, d;
  cin >> n;
  while (n--) {
    cin >> a >> b >> c >> d;
    sort(a, b, c);
    printf("%lld\n", solve(a, b, c, d));
  }
  return 0;
}

