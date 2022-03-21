#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, b, k;
  cin >> t;
  while (t--) {
    cin >> b >> k;
    --b;
    int res = 0;
    for (ll d = 1; d * d <= b; ++d) {
      if (b % d == 0)  {
        int x = d, y = b / d;
        if (x <= k && x <= b) res = max(res, x);
        if (y <= k && y <= b) res = max(res, y);
      }
    }
    cout << res << endl;
  }
  return 0;
}

