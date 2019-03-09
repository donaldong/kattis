#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pt {
  int r, c;
  bool s;
  bool operator<(const pt &p) const {
    if (r != p.r) return r < p.r;
    return c < p.c;
  }
};

typedef vector<pt> vpt;
bool locked = false;
int MOD = 1e9 + 7;
int R, C;
vpt P;

ll power2(int n) {
  if (!n) return 1;
  ll res = power2(n / 2);
  if (n & 1) return ((res * res) % MOD * 2) % MOD;
  return (res * res) % MOD;
}

ll solve() {
  int n = 0;
  sort(P.begin(), P.end());
  size_t a, b, i, k = P.size();
  for (a = 0; a < k;) {
    for (b = a + 1; b < k && P[a].r == P[b].r; ++b);
    for (i = a + 1; i < b; ++i) {
      if (
        (P[a].c + P[a].s) % 2 != \
        (P[i].c + P[i].s) % 2
      ) {
        locked = true;
        return false;
      }
    }
    a = b, ++n;
  }
  return power2(R - n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  char sign;
  cin >> R >> C >> k;
  P.resize(k);
  for (int i = 0; i < k; ++i) {
    cin >> sign >> P[i].r >> P[i].c;
    P[i].s = sign == '+';
  }
  ll res = solve();
  swap(R, C);
  for (auto &p : P) swap(p.r, p.c);
  res = res + solve();
  if (!locked) res -= k ? 1 : 2, res = res + MOD;
  printf("%lld\n", res % MOD);
  return 0;
}
