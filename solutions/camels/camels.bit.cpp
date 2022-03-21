#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

class Fenwick {
public:
  vi T, v;

  Fenwick(const vi &A, const vi &B) : T(A.size(), 0), v(A.size()) {
    vi ord(A.size());
    for (int i = 0; i < A.size(); ++i) ord[A[i]] = i;
    for (int i = 0; i < A.size(); ++i) v[i] = ord[B[i]];
  }

  void add(int i) {
    for (++i; i < v.size(); i += i & -i) ++T[i];
  }
  
  ll query(int i) {
    ll res = 0;
    for (; i; i -= i & -i) res += T[i];
    return res;
  }

  ll num_inv() {
    ll res = v.size(), j = v.size() - 1;
    res *= j;
    res >>= 1;
    for (int i = 0; i <= j; ++i) {
      res -= query(v[i]);
      add(v[i]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi A(n), B(n), C(n);
  for (auto &e : A) cin >> e, --e;
  for (auto &e : B) cin >> e, --e;
  for (auto &e : C) cin >> e, --e;
  Fenwick T[] = { Fenwick(A, B), Fenwick(A, C), Fenwick(B, C) };
  ll res = n, inv = 0;
  res *= (n - 1);
  res >>= 1;
  for (int i = 0; i < 3; ++i) {
    inv += T[i].num_inv();
  }
  printf("%lld\n", res - (inv >> 1));
  return 0;
}
