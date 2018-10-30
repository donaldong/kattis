#include <bits/stdc++.h>
using namespace std;

struct pt;
using ld = long double;
using vi = vector<int>;
using vpt = vector<pt>;
ld EPS = 1e-8;

struct pt {
  ld l, r;
  int i;
  pt() {}
  pt(ld l, ld r) : l(l), r(r) {}
};

bool solve(vpt &P, ld A, ld B, vi &res) {
  size_t i = 0, j;
  while (i < P.size() && P[i].r < A) ++i;
  while (i < P.size()) {
    ld r = -1e300;
    j = -1;
    for (; i < P.size() && P[i].l < A + EPS; ++i) {
      if (P[i].r > r) {
        r = P[i].r;
        j = i;
      }
    }
    if (j == -1) return false;
    res.push_back(P[j].i);
    A = r;
#ifdef DEBUG
    printf("picked %d [%.3Lf, %.3Lf]\n", P[j].i, P[j].l, P[j].r);
#endif
    if (A + EPS > B) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ld A, B;
  int n;
  while (cin >> A >> B) {
    cin >> n;
    vpt P(n);
    for (int i = 0; i < n; ++i) cin >> P[i].l >> P[i].r, P[i].i = i;
    sort(P.begin(), P.end(), [](pt &a, pt &b) {
      if (a.l == b.l) return a.r > b.r;
      return a.l < b.l;
    });
    vi res;
    if (!solve(P, A, B, res)) cout << "impossible" << endl;
    else {
      cout << res.size() << endl;
      for (auto r : res) cout << r << ' ';
      cout << endl;
    }
  }
  return 0;
}
