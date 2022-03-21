#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b;
  edge() {}
  edge(int a, int b) : a(a), b(b) {}
};

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<edge> ve;

const int MAX_NODE = 1e5; 
const int MAX_LEVEL = ceil(log(MAX_NODE) / log(2));
int ord_counter;
ve E; // Edges
vi C; // Minister counter for each node
vi depth; // depth
vi ord; // the order of the nodes via dfs
v2i P; // P[i][j]: Parent of node i at level j
v2i G; // Graph: A adj list

void dfs_build(int a, int b) {
  P[b][0] = a;
  ord[b] = ord_counter++;
  depth[b] = depth[a] + 1;
  for (int c : G[b]) {
    if (c == a) continue;
    dfs_build(b, c);
  }
}

int lca(int a, int b) {
  int d = depth[b] - depth[a], l = 0;
  if (d < 0) swap(a, b), d *= -1;
#ifdef DEBUG
  printf("lca(%d, %d):\n", a + 1, b + 1);
#endif
  // lift node b to the same level as node a
  for (int i = MAX_LEVEL; i-- > 0;) {
    if (d & (1 << i) ) b = P[b][i];
  }
  // lift both nodes util find lca
  for (int i = MAX_LEVEL; i-- > 0;) {
#ifdef DEBUG
    printf(
      "the parent nodes with dist of 2^%d is %d for node %d, and %d for node %d\n",
      i, P[a][i] + 1, a + 1, P[b][i] + 1, b + 1
    );
#endif
    if (P[a][i] != P[b][i]) {
      a = P[a][i], b = P[b][i];
    }
  }
  if (a == b) return a;
  return P[a][0];
}

void dfs_count(int a, int b) {
  for (int c : G[b]) {
    if (c == a) continue;
    dfs_count(b, c);
  }
  C[a] += C[b];
#ifdef DEBUG
  printf("node %d has be named by %d ministers\n", b + 1, C[b]);
#endif
}

int main() {
  ios::sync_with_stdio(0);

  int n, m, k, a, b, p;
  scanf("%d %d %d", &n, &m, &k);

  // Build the graph
  E.resize(n - 1), ord.resize(n), C.assign(n, 0), G.resize(n);
  P.assign(n, vi(MAX_LEVEL)), depth.assign(n, 0);
  for (size_t i = 0; i < E.size(); ++i) {
    scanf("%d %d", &a, &b);
    --a, --b;
    E[i].a = a, E[i].b = b;
    G[a].push_back(b), G[b].push_back(a);
  }
  ord_counter = 0;
  dfs_build(0, 0);

  // Binary Lifting
  for (int j = 1; j < MAX_LEVEL; ++j) {
    for (int i = 0; i < n; ++i) {
      P[i][j] = P[P[i][j - 1]][j - 1];
    }
  }

  // Process each query
  while (m--) {
    scanf("%d", &n);
    vi nodes(n);
    for (auto &node : nodes) scanf("%d", &node), --node;
    sort(nodes.begin(), nodes.end(), [](int a, int b) {
      return ord[a] < ord[b];
    });
    for (int i = 0; i < n; ++i) {
      a = nodes[i], b = nodes[(i + 1) % n], p = lca(a, b);
      ++C[a], ++C[b], C[p] -= 2;
#ifdef DEBUG
      printf(
        "lca(%d, %d) = %d\n (%d %d %d)\n",
        a + 1, b + 1, p + 1, C[a], C[b], C[p]
      );
#endif
    }
  }
  dfs_count(0, 0);

  // Output
  vi res; res.reserve(E.size());
  for (size_t i = 0; i < E.size(); ++i) {
    a = E[i].a, b = E[i].b;
    if (ord[a] > ord[b]) swap(a, b);
    if (C[b] >= 2 * k) res.push_back(i + 1); 
  }
  printf("%zu\n", res.size());
  if (!res.empty()) {
    for (auto r : res) printf("%d ", r);
    printf("\n");
  }
  return 0;
}
