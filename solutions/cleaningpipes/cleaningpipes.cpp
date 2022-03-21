#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ti2 = tuple<int, int>;
using ti3 = tuple<int, int, int>;
using vti2 = vector<ti2>;
using vti3 = vector<ti3>;
using vb = vector<bool>;
using v2b = vector<vb>;

vi sub(vi &a, vi &b) {
  return {a[0] - b[0], a[1] - b[1]};
}

int cross(vi &a, vi &b) {
  return a[0] * b[1] - b[0] * a[1];
}

int dir(vi &a, vi &b, vi &c) {
  auto ab = sub(b, a);
  auto ac = sub(c, a);
  int r = cross(ac, ab);
  if (!r) return 0;
  if (r > 0) return 1;
  return 2;
}

bool on_seg(vi &a, vi &b, vi &c) {
  return b[0] <= max(a[0], c[0]) && 
    b[0] >= min(a[0], c[0]) && 
    b[1] <= max(a[1], c[1]) && 
    b[1] >= min(a[1], c[1]);
}

bool intersect(vti2 &W, ti3& A, ti3 &B) {
  vi a(2), b(2), c(2), d(2);
  int i, j; 
  tie(i, b[0], b[1]) = A;
  tie(j, d[0], d[1]) = B;
  if (i == j) return false;
  tie(a[0], a[1]) = W[i];
  tie(c[0], c[1]) = W[j];
  vi D(4);
  D[0] = dir(a, b, c);
  D[1] = dir(a, b, d);
  D[2] = dir(c, d, a);
  D[3] = dir(c, d, b);
  if (D[0] != D[1] && D[2] != D[3]) return true;
  return (!D[0] && on_seg(a, c, b)) ||
    (!D[1] && on_seg(a, d, b)) ||
    (!D[2] && on_seg(c, a, d)) ||
    (!D[3] && on_seg(c, b, d));
}

struct node {
  int col = -1;
  vector<node*> neigh;
};

bool dfs(node *n, int col) {
  if (n->col != -1) return n->col == col;
  n->col = col;
  for (auto c : n->neigh) {
    if (!dfs(c, !col)) return false;
  }
  return true;
}

bool possible(vti2 &W, vti3 &P) {
  vector<node> N(P.size());
  for (size_t i = 0; i < P.size(); ++i) {
    for (size_t j = i + 1; j < P.size(); ++j) {
      if (!intersect(W, P[i], P[j])) continue;
      N[i].neigh.push_back(&N[j]);
      N[j].neigh.push_back(&N[i]);
    }
  }
  for (auto &n : N) if (n.col == -1) {
    if (!dfs(&n, 0)) return false;
  }
  return true;
}

int main() {
  int w, p;
  cin >> w >> p;
  vti2 W(w);
  for (auto &e : W) {
    int x, y;
    cin >> x >> y;
    e = make_tuple(x, y);
  } 
  vti3 P(p);
  for (auto &e : P) {
    int s, x, y;
    cin >> s >> x >> y;
    e = make_tuple(--s, x, y);
  }
  cout << (possible(W, P) ? "possible" : "impossible") << endl;
  return 0;
}
