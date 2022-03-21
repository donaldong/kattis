#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b, w;
  bool in_mst = false;
  edge() {}
  edge(int a, int b, int w) : a(a), b(b), w(w) {}
};

struct cmp {
  bool operator()(edge *a, edge *b) const {
    if (a->w == b->w) return a < b;
    return a->w < b->w;
  }
};

using pq = set<edge*, cmp>; 
using ve = vector<edge*>;
using v2e = vector<ve>;
using ti2 = tuple<int, int>;
using vti2 = vector<ti2>;
using vb = vector<bool>;

void enque(pq &Q, int cur, v2e &E, vb &mark) {
  mark[cur] = true;
  for (auto e : E[cur]) {
    if (mark[e->a] && mark[e->b]) continue;
    Q.insert(e);
  }
}

int prim(v2e &E) {
  pq Q;
  vb mark(E.size(), false);
  int sum = 0, nxt;
  enque(Q, 0, E, mark);
  while (!Q.empty()) {
    auto e = *Q.begin(); Q.erase(Q.begin());
    if (mark[e->a] && mark[e->b]) continue;
    sum += e->w;
    e->in_mst = true;
    nxt = mark[e->a] ? e->b : e->a;
    enque(Q, nxt, E, mark);
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a, b, w;
  while (cin >> n >> m) {
    if (!n && !m) break;
    v2e E(n);
    ve refs;
    refs.reserve(m);
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> w;
      edge *e =  new edge(a, b, w);
      E[a].push_back(e);
      E[b].push_back(e);
      refs.push_back(e);
    }
    if (m < n - 1) cout << "Impossible" << endl;
    else {
      cout << prim(E) << endl;
      vti2 P;
      P.reserve(n - 1);
      for (auto r : refs) if (r->in_mst) P.emplace_back(
        min(r->a, r->b), max(r->a, r->b)
      );
      if (P.size() != n - 1) {
        cout << "Impossible" << endl;
      } else {
        sort(P.begin(), P.end());
        for (auto &p : P) {
          tie(a, b) = p;
          cout << a << " " << b << endl;
        }
      }
    }
    for (auto r : refs) delete r;
  }
  return 0;
}
