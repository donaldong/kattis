#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using tld = tuple<ld, ld>;
using vtld = vector<tld>;
using vi = vector<int>;
using vb = vector<bool>;

struct edge {
  int a, b;
  bool in_mst = false, in_matching = false, used = false;
  ld w;
  edge() {}
  edge(int a, int b, ld w) : a(a), b(b), w(w) {}
};

using ve = vector<edge>;
using vep = vector<edge*>;
using v2ep = vector<vep>;
int NUM_OF_NODES;

void debug(vi &V) {
  for (int v : V) cout << v << " ";
  cout << endl;
}

int find(vi &P, int n) {
  if (P[n] == -1) return n;
  return P[n] = find(P, P[n]);
}

void mst(ve &E) {
  int a, b;
  sort(E.begin(), E.end(), [](edge &a, edge &b) {
    return a.w < b.w;
  });
  vi P(NUM_OF_NODES, -1);
  for (size_t i = 0; i < E.size(); ++i) {
    a = find(P, E[i].a), b = find(P, E[i].b);
    if (a != b) P[b] = a, E[i].in_mst = true;
  }
}

vi odd_vertices(ve &E) {
  vi count(NUM_OF_NODES, 0);
  vi O;
  for (auto &e : E) if (e.in_mst) ++count[e.a], ++count[e.b];
  for (int i = 0; i < NUM_OF_NODES; ++i) {
    if (count[i] & 1) O.push_back(i);
  }
  return O;
}

void math(vi &O, v2ep &M) {
  vb matched(NUM_OF_NODES, false);
  int a, b;
  for (auto n : O) {
    bool f = false;
    sort(M[n].begin(), M[n].end(), [](edge *a, edge *b) {
      return a->w < b->w;
    });
    for (auto itr = M[n].begin(); itr != M[n].end(); ++itr) {
      auto e = *itr;
      a = e->a, b = e->b;
      if (matched[a] || matched[b] || e->in_matching) continue;
      e->in_matching = true;
      matched[a] = matched[b] = true;
      f = true;
      break;
    }
    if (!f) a = b / 0;
  }
}

vi eulerian(v2ep &M) {
  vi res;
  stack<int> S;
  int n = 0;
  S.push(0);
  while (!S.empty()) {
    bool f = false;
    for (auto &ep : M[n]) {
      if (ep->used) continue;
      if (!ep->in_matching && !ep->in_mst) continue;
      S.push(n);
      ep->used = true;
      f = true;
      n = ep->a == n ? ep->b : ep->a;
    }
    if (!f) {
      res.push_back(n);
      n = S.top();
      S.pop();
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

vi hamiltonian(vi &C) {
  vb seen(NUM_OF_NODES, false);
  vi res;
  res.reserve(NUM_OF_NODES);
  for (auto c : C) {
    if (seen[c]) continue;
    res.push_back(c);
    seen[c] = true;
  }
  return res;
}

vi christofides(ve &E) {
  mst(E);
  auto O = odd_vertices(E);
  v2ep M(NUM_OF_NODES);
  for (auto &e : E) {
    M[e.a].push_back(&e);
    M[e.b].push_back(&e);
  }
  math(O, M); 
  auto C = eulerian(M);
  return hamiltonian(C);
}

int main() {
  int n;
  ld x, y;
  cin >> n;
  NUM_OF_NODES = n;
  vtld N;
  N.reserve(n);
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    N.emplace_back(x, y);
  }
  vector<edge> E;
  E.reserve(n * (n - 1) / 2);
  for (int i = 1; i < n; ++i) for (int j = 0; j < i; ++j) {
    ld dx = get<0>(N[i]) - get<0>(N[j]), dy = get<1>(N[i]) - get<1>(N[j]);
    E.emplace_back(j, i, hypot(dx, dy));
  }
  vi tour = christofides(E);
  for (int t : tour) cout << t << endl;
  return 0;
}
