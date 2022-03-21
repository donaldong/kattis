#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

class SegTree {
public:
  vi st, v;

  SegTree(const vi &A, const vi &B) : st(4 * A.size(), 0), v(A.size()) {
    vi ord(A.size());
    for (int i = 0; i < A.size(); ++i) ord[A[i]] = i;
    for (int i = 0; i < A.size(); ++i) v[i] = ord[B[i]];
  }

  void insert(int p, int L, int R, int i) {
    if (i > R || i < L) return;
    ++st[p]; 
    if (L == R) return;
    int mid = (L + R) >> 1;
    insert(left(p), L, mid, i);
    insert(right(p), mid + 1, R, i);
  }

  ll query(int p, int L, int R, int l, int r) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) return st[p];
    int mid = (L + R) >> 1;
    return query(left(p), L, mid, l, r) + \
           query(right(p), mid + 1, R, l, r);
  }

  ll num_inv() {
    ll res = 0, j = v.size() - 1;
    for (int i = 0; i <= j; ++i) {
      res += query(1, 0, j, 0, v[i]);
      insert(1, 0, j, v[i]);
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
  SegTree T[] = { SegTree(A, B), SegTree(A, C), SegTree(B, C) };
  ll res = -n;
  res *= (n - 1);
  res >>= 1;
  for (int i = 0; i < 3; ++i) {
    res += T[i].num_inv();
  }
  printf("%lld\n", res / 2);
  return 0;
}
