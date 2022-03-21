#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
};

using vb = vector<bool>;
using vi = vector<int>;
using vpt = vector<pt>;
using v2pt = vector<vpt>;
int INF = 1e9 + 7;
vpt P;   // points
v2pt ST; // segment tree

bool replacable(pt &a, pt &b, int opt) {
  if (opt == 0) return a.y > b.y;
  if (opt == 1) return a.x > b.x; 
  if (opt == 2) return a.y < b.y;
  return a.x < b.x;
}

pt get(int i, const vpt &A, const vpt &B) {
  return i < A.size() ? A[i] : B[i - A.size()];
}

void mark_bound(vb &M, const vpt &A, const vpt &B) {
  vi pos(4, -1);
  vpt cords = {pt(0, -INF), pt(-INF, 0), pt(0, INF), pt(INF, 0)};
  for (size_t i = 0; i < M.size(); ++i) {
    if (M[i]) continue;
    pt p = get(i, A, B);
    for (int j = 0; j < 4; ++j) {
      if (replacable(p, cords[j], j)) pos[j] = i, cords[j] = p;
    }
  }
  for (int p : pos) if (p >= 0) M[p] = true;
}

vpt merge(const vpt &A, const vpt &B) {
  if (A.empty()) return B;
  if (B.empty()) return A;
  vb M(A.size() + B.size(), false); // mark array
  mark_bound(M, A, B); // outer boundary
  mark_bound(M, A, B); // inner boundary
  vpt res;
  for (size_t i = 0; i < M.size(); ++i) {
    if (M[i]) res.push_back(get(i, A, B));
  }
  return res;
}

int left(int n) { return n << 1; }
int right(int n) { return (n << 1) + 1; }

void build(int n, int l, int r) {
  if (l == r) { ST[n] = {P[l]}; return; }
  int k = (l + r) / 2;
  build(left(n), l, k); 
  build(right(n), k + 1, r); 
  ST[n] = merge(ST[left(n)], ST[right(n)]);
}

vpt query(int n, int l, int r, int i, int j) {
  if (i > r || j < l) return {};
  if (l >= i && r <= j) return ST[n];
  int k = (l + r) / 2;
  return merge(
    query(left(n), l, k, i, j),
    query(right(n), k + 1, r, i, j)
  );
}

ll exclude(size_t k, const vpt &bound) {
  int t = -INF, r = -INF, b = INF, l = INF;
  for (size_t i = 0; i < bound.size(); ++i) {
    if (i == k) continue;
    t = max(t, bound[i].y); b = min(b, bound[i].y);
    r = max(r, bound[i].x); l = min(l, bound[i].x);
  }
  ll dy = t, dx = r;
  dy -= b, dx -= l;
  return max(dy, dx);
}

ll min_side(const vpt &bound) {
  if (bound.size() <= 2) return 0;
  ll res = 1e18;
  for (size_t i = 0; i < bound.size(); ++i) {
    res = min(res, exclude(i, bound));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q, a, b;
  cin >> n >> q;
  P.resize(n);
  ST.resize(4 * n);
  for (int i = 0; i < n; ++i) cin >> P[i].x >> P[i].y;
  build(1, 0, n - 1);
  while (q--) {
    cin >> a >> b;
    cout << min_side(query(1, 0, n - 1, --a, --b)) << endl;
  }
  return 0;
}
