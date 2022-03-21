#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n;
  ll res = 0;
  while (n--) {
    cin >> k;
    if (k < 0) res -= k;
  }
  printf("%lld\n", res);
  return 0;
}
