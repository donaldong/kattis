#include <bits/stdc++.h>
using namespace std;

struct node;
using vn = vector<node>;
using vi = vector<int>;
using v2i = vector<vi>;

struct node {
  int p = -1;
  // identifier
  int r = -1;
  // children
  vector<int> C;
  // count
  int k = 0, i;
  bool visited = false;
};

vn N;
v2i LCA;

void build(int k) {
  auto &n = N[k];
  n.visited = true;
  LCA[k][k] = k;
  for (auto &e : n.C) {
    auto &c = N[e];
    if (c.visited) {
      e = -1;
      continue;
    }
    LCA[k][e] = k;
    LCA[e][k] = k;
    c.p = k;
    build(e);
  }
}

void fill() {
  for (auto &n : N) {
    int p = n.p;
    while (p != -1) {
      auto &cur = N[p];
      LCA[n.i][cur.i] = cur.i;
      LCA[cur.i][n.i] = cur.i;
      p = cur.p;
    }
  }
}

int lca(int a, int b) {
  if (LCA[a][b] != -1) return LCA[a][b];
  int r = N[a].p;
  while (LCA[r][b] == -1) {
    r = N[r].p;
  }
  LCA[a][b] = r;
  LCA[b][a] = r;
  return r;
}

void update(vi &S) {
  int root = S[0];
  for (size_t i = 1; i < S.size(); ++i) root = lca(root, S[i]);
  for (auto cur : S) {
    while (cur != root) {
      auto &n = N[cur];
      n.visited = false;
      cur = n.p;
    }
  }
  for (auto cur : S) {
    while (cur != root) {
      auto &n = N[cur];
      if (n.visited) break;
      n.visited = true;
      ++n.k;
      cur = n.p;
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  N = vn(n);
  LCA = v2i(n, vi(n, -1));
  vector<tuple<int, int>> E(n - 1);
  for (int i = 0; i < n; ++i) N[i].i = i;
  for (size_t i = 0; i < E.size(); ++i) {
    int a, b;
    cin >> a >> b;
    E[i] = make_tuple(--a, --b);
    auto &na = N[a];
    auto &nb = N[b];
    na.C.push_back(b);
    nb.C.push_back(a);
  }
  // rooted at node 0
  build(0);
  fill();
  for (size_t i = 0; i < E.size(); ++i) {
    int a, b;
    tie(a, b) = E[i];
    auto &na = N[a];
    auto &nb = N[b];
    if (na.p == nb.i) na.r = i + 1;
    else nb.r = i + 1;
  }
  while (m--) {
    int s;
    cin >> s;
    vi S(s);
    for (auto &e : S) {
      cin >> e;
      --e;
    }
    update(S);
  }
  vi res;
  for (auto e : N) if (e.k >= k) res.push_back(e.r);
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int r : res) cout << r << " ";
  cout << endl;
  return 0;
}
