#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b, w;
  bool in_mst = false;
  edge() {}
  edge(int a, int b, int w) : a(a), b(b), w(w) {}
};

using ll = long long;
using vi = vector<int>;

int find(vi &P, int n) {
  if (P[n] == -1) return n;
  return P[n] = find(P, P[n]);
}

using ve = vector<edge>;

bool valid(vi &P) {
  int p = find(P, 0);
  for (size_t i = 1; i < P.size(); ++i) {
    if (p != find(P, i)) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    ve E(m);
    int a, b;
    for (auto &e : E) {
      cin >> e.a >> e.b >> e.w;
      if (e.a > e.b) swap(e.a, e.b);
    }
    sort(E.begin(), E.end(), [](edge &a, edge &b) {
      return a.w < b.w;
    });
    ll res = 0, seen = 0;
    vi P(n, -1);
    for (size_t i = 0; i < E.size(); ++i) {
      a = find(P, E[i].a), b = find(P, E[i].b);
      if (a != b) {
        ++seen;
        res += E[i].w;
        P[b] = a;
        E[i].in_mst = true;
      }
      if (seen == n - 1) break;
    }
    if (seen != n - 1 || !valid(P)) cout << "Impossible" << endl;
    else {
      cout << res << endl;
      sort(E.begin(), E.end(), [](edge &a, edge &b) {
        if (a.a == b.a) return a.b < b.b;
        return a.a < b.a;
      });
      for (auto &e : E) if (e.in_mst) cout << e.a << " " << e.b << endl;
    }
  }
  return 0;
}
