#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int X, int Y) {
  ll res = 0;
  for (int i = 0;; ++i) {
    ll new_pts = 1 << i, x = 0, y = 0;
    if (new_pts > X) x = new_pts - X;
    if (new_pts > Y) y = new_pts - Y;
    if (new_pts - x - y <= 0) return res;
    res += new_pts - x - y;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N, X, Y;
  cin >> N;
  while (N--) {
    cin >> X >> Y;
    printf("%lld\n", solve(X + 1, Y + 1));
  }
  return 0;
}
