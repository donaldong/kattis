/**
 * @date        2022-05-10
 * @tags        tree, graph, greedy
 * @difficulty  1900
 */
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;

  vector<vi> adj(N+1);
  for (int i = 1, u, v; i < N; ++i) {
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }

  vi leafCnts(N+1, 0), parent(N+1, 0);
  function<void(int,int)> dfsRoot = [&](int p, int u) {
    for (int v : adj[u]) {
      if (v == p) continue;
      dfsRoot(u, v);
      leafCnts[u] += leafCnts[v];
      parent[v] = u;
    }
    if (adj[u].size() == 1) ++leafCnts[u];
  };
  int root = 1;
  dfsRoot(0, root);

  int totLeafCnt = leafCnts[root];
#ifdef DEBUG
    fprintf(stderr, "totLeafCnt=%d\n", totLeafCnt);
#endif
  for (int u = 1, minLeafCnt = INT_MAX; u <= N; ++u) {
    int leafCnt = totLeafCnt - leafCnts[u];
    for (int v : adj[u]) {
      if (v == parent[u]) continue;
      leafCnt = max(leafCnt, leafCnts[v]);
    }
#ifdef DEBUG
    fprintf(stderr, "leafCnt for node %d: %d\n", u, leafCnt);
#endif
    if (leafCnt < minLeafCnt) {
      minLeafCnt = leafCnt;
      root = u;
    }
  }

  function<vi(int,int)> getLeaves = [&](int p, int u) {
    vi leaves;
    if (adj[u].size() == 1) leaves.push_back(u);
    for (int v : adj[u]) {
      if (v == p) continue;
      auto l = getLeaves(u, v);
      leaves.insert(leaves.end(), l.begin(), l.end());
    }
    return leaves;
  };

  vector<vi> groups;
  priority_queue<pair<int,int>> pq;
  groups.reserve(adj[root].size());
  for (int v : adj[root]) {
    auto leaves = getLeaves(root, v);
    pq.emplace(leaves.size(), groups.size());
    groups.emplace_back(move(leaves));
  }

#ifdef DEBUG
  fprintf(stderr, "root=%d\n", root);
  for (int i = 0; i < groups.size(); ++i) {
    fprintf(stderr, "group %d: ", i);
    for (int v : groups[i]) cerr << v << ' ';
    cerr << endl;
  }
  cerr << endl;
#endif

  vector<pair<int,int>> res;
  res.reserve(N);
  while (pq.size() >= 2) {
    auto [l1, a] = pq.top(); pq.pop();
    auto [l2, b] = pq.top(); pq.pop();
    auto& A = groups[a];
    auto& B = groups[b];
    res.emplace_back(A.back(), B.back());
    A.pop_back(), B.pop_back();
    if (!A.empty()) pq.emplace(A.size(), a);
    if (!B.empty()) pq.emplace(B.size(), b);
  }

#ifdef DEBUG
  fprintf(stderr, "after matching:");
  for (int i = 0; i < groups.size(); ++i) {
    fprintf(stderr, "group %d: ", i);
    for (int v : groups[i]) cerr << v << ' ';
    cerr << endl;
  }
  cerr << endl;
#endif

  if (pq.size() == 1) {
    auto [l, a] = pq.top(); pq.pop();
    auto& leaves = groups[a];
    for (auto v : leaves) res.emplace_back(root, v);
  }

  printf("%lu\n", res.size());
  for (auto [a, b] : res) printf("%d %d\n", a, b);
  return 0;
}
