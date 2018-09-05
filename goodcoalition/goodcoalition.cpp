#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using vld = vector<ld>;

int MAX_SEATS = 151;

ld solve(vld &P, int s) {
  if (P[s] > -0.5) return P[s];
  ld res = 0;
  for (int i = 1; 2 * i < s; ++i) {
    res = max(res, solve(P, i) * solve(P, s - i));
  }
  cout << s << " " << res << endl;
  P[s] = res;
  return res;
}

int main() {
  int t, n, s;
  ld p;
  cin >> t;
  while (t--) {
    cin >> n;
    vld P(MAX_SEATS, -1);
    while (n--) {
      cin >> s >> p;
      P[s] = max(P[s], p / 100.0);
    }
    p = 0;
    for (int i = 76; i <= 150; ++i) p = max(p, solve(P, i));
    cout << p * 100.0 << endl;
  }
  return 0;
}
