#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int count(int a, int b, int d) {
  int diff = b - a;
  if (diff < 0) return 0;
  return diff / d + 1;
}

int main() {
  int l, d, n;
  cin >> l >> d >> n;
  if (!n) {
    cout << count(6, l - 6, d) << endl;
  } else {
    vi N(n);
    for (auto &e : N) cin >> e;
    sort(N.begin(), N.end());
    int res = count(6, N[0] - d, d);
    for (int i = 1; i < n; ++i) {
      res += count(N[i - 1] + d, N[i] - d, d);
    }
    res += count(N.back() + d, l - 6, d);
    cout << res << endl;
  }
  return 0;
}
