#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ti2 = tuple<int, int>;
using ti3 = tuple<int, int, int>;
using vti2 = vector<ti2>;
using vti3 = vector<ti3>;
using vb = vector<bool>;
using v2b = vector<vb>;

bool intersect(vti2 &W, ti3& A, ti3 &B) {
  vi X(4), Y(4);
  int i, j; 
  tie(i, X[1], Y[1]) = A;
  tie(j, X[3], Y[3]) = B;
  if (i == j) return false;
  tie(X[0], Y[0]) = W[i];
  tie(X[2], Y[2]) = W[j];
  bool aymin = min(Y[0], Y[1]);
  bool aymax = max(Y[0], Y[1]);
  bool bymin = min(Y[2], Y[3]);
  bool bymax = max(Y[2], Y[3]);
  if (aymin > bymax || bymin > aymax) return false;
  bool axmin = min(X[0], X[1]);
  bool axmax = max(X[0], X[1]);
  bool bxmin = min(X[2], X[3]);
  bool bxmax = max(X[2], X[3]);
  return axmin <= bxmax && bxmin <= axmax;
}

struct node {
  bool f = false;
  vector<node*> neigh;
};

bool dfs(node *n, node *prev, int step) {
  for (auto c : n->neigh) {
    if (c == prev) continue;
    if (c->f) {
      if (step & 1) continue;
      return false;
    }
    c->f = true;
    if (!dfs(c, n, step + 1)) return false;
  }
  return true;
}

bool possible(vti2 &W, vti3 &P) {
  vector<node*> N(P.size());
  for (auto &n : N) n = new node();
  for (size_t i = 0; i < P.size(); ++i) {
    for (size_t j = i + 1; j < P.size(); ++j) {
      if (!intersect(W, P[i], P[j])) continue;
      N[i]->neigh.push_back(N[j]);
      N[j]->neigh.push_back(N[i]);
    }
  }
  for (auto n : N) if (!n->f) {
    n->f = true;
    if (!dfs(n, 0, 0)) return false;
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
