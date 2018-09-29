#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct piece {
  int l, f, b;
  vi V;
  piece() {}
  piece(int l, int f, int b) : l(l), f(f), b(b) {}
};

struct cmp {
  bool operator()(const piece &a, const piece &b) const {
    if (a.l != b.l) return a.l < b.l;
    if (a.f != b.f) return a.f < b.f;
    if (a.b != b.b) return a.b < b.b;
    return &a < &b;
  }
};

using sp = set<piece, cmp>;

void debug(piece p, string s="") {
  cout << s << endl;
  cout << p.l << " " << p.b << endl;
  cout << endl;
}

bool update(sp &S) {
  auto a = S.begin();
  piece p(a->l, a->b + 1, 0);
  auto b = S.lower_bound(p);
  if (b == S.end()) return false;
  p.l = a->l + b->l;
  p.f = min(a->f, b->f);
  p.b = max(a->b, b->b);
  auto c = p.V.insert(p.V.begin(), a->V.begin(), a->V.end());
  c = p.V.insert(c, b->V.begin(), b->V.end());
  S.erase(a); S.erase(b);
  S.insert(p);
  return true;
}

int main() {
  int n, b;
  bool f = true;
  while (cin >> n) {
    if (!n) break;
    sp S;
    while (n--) {
      cin >> b;
      piece p(1, b, b);
      p.V = {b};
      S.insert(p);
    }
    while (update(S));
    if (!f) cout << endl;
    f = false;
    cout << S.size() << endl;
    for (auto &p : S) {
      vi V = p.V;
      sort(V.begin(), V.end());
      for (auto &e : V) cout << e << " ";
      cout << endl;
    }
  }
  return 0;
}
