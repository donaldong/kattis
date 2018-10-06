#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using tld = tuple<ld, ld>;
using vtld = vector<tld>;
using vi = vector<int>;
using vb = vector<bool>;

struct edge {
  int a, b, used_count = 0;
  bool in_mst = false;
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

void dfs(v2ep &M, int n, vi &path, vb &V) {
  if (V[n]) return;
  V[n] = true;
  path.push_back(n);
  for (auto ep : M[n]) {
    if (!ep->in_mst) continue;
    dfs(M, ep->a == n ? ep->b : ep->a, path, V);
  }
}

vi get_tour(ve &E) {
  mst(E);
  v2ep M(NUM_OF_NODES);
  for (auto &e : E) {
    M[e.a].push_back(&e);
    M[e.b].push_back(&e);
  }
  vi path;
  vb V(NUM_OF_NODES, false);
  dfs(M, 0, path, V);
  return path;
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
  vi tour = get_tour(E);
  for (int t : tour) cout << t << endl;
  return 0;
}
