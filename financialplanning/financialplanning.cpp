#include <bits/stdc++.h>
using namespace std;

struct rat;
struct tup;
using ll = long long;
using vt = vector<tup>;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

struct rat {
  ll a, b;

  rat(ll _a, ll _b) {
    ll k = gcd(_a, _b);
    a = _a / k, b = _b / k;
  }

  bool operator<(const rat &r) const {
    __int128 A = a, B = r.a;
    A *= r.b, B *= b;
    return A < B;
  }

  ll ceil() {
    ll res = a / b;
    if (a % b)  ++res;
    return res;
  }
};

struct tup {
  rat d;
  int c, p;
  tup() : d(1, 0) {}
  tup(int a, int b) :
    d(a, b), c(a), p(b) {}
};


ll solve(vt &invs, int m) {
  ll C = m, P = 0;
  rat res(1, 0), r(1, 0);
  int c, p;
  for (auto &inv : invs) {
    C += inv.c, P += inv.p;
    r = rat(C, P);
    if (r < res) res = r;
    else break;
#ifdef DEBUG
    printf("%lld / %lld: %.3lf\n", inv.d.a, inv.d.b, double(inv.d.a) / inv.d.b);
    printf("C: %lld P: %lld => %lld / %lld\n", C, P, res.a, res.b);
#endif
  }
  return res.ceil();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, c, p;
  cin >> n >> m;
  vt invs(n); 
  for (int i = 0; i < n; ++i) {
    cin >> p >> c;
    invs[i] = tup(c, p);
  }
  sort(invs.begin(), invs.end(), [](tup &a, tup &b) {
    return a.d < b.d;
  });

  printf("%lld\n", solve(invs, m));
  return 0;
}
