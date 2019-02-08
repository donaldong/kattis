#include <bits/stdc++.h>
using namespace std;

struct pt {
  int r, c, i;
};
using vp = vector<pt>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, r, c;
  cin >> n;
  vp P(n);
  for (int i = 0; i < n; ++i) {
    cin >> P[i].r >> P[i].c;
    P[i].i = i + 1;
  }

  char opt;
  int res = 0, k;
  stringstream ss;
  sort(P.begin(), P.end(), [](const pt &a, const pt &b) {
    return a.r > b.r;
  });

  opt = 'D';
  for (int i = 0; i < n; ++i) {
    k = n - i - P[i].r;
    if (k <= 0) continue;
    res += k;
    while (k--) {
      ss << P[i].i << ' ' << opt << '\n';
    }
  }

  opt = 'U';
  for (int i = n; i-- > 0;) {
    k = n - i - P[i].r;
    if (k >= 0) continue;
    k *= -1;
    res += k;
    while (k--) {
      ss << P[i].i << ' ' << opt << '\n';
    }
  }

  sort(P.begin(), P.end(), [](const pt &a, const pt &b) {
    return a.c > b.c;
  });

  opt = 'R';
  for (int i = 0; i < n; ++i) {
    k = n - i - P[i].c;
    if (k <= 0) continue;
    res += k;
    while (k--) {
      ss << P[i].i << ' ' << opt << '\n';
    }
  }

  opt = 'L';
  for (int i = n; i-- > 0;) {
    k = n - i - P[i].c;
    if (k >= 0) continue;
    k *= -1;
    res += k;
    while (k--) {
      ss << P[i].i << ' ' << opt << '\n';
    }
  }

  cout << res << '\n' << ss.rdbuf();
  return 0;
}
