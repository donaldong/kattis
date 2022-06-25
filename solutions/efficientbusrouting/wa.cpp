/**
 * NOTE: This is not a working solution (WA on test case 6)
 *
 * @date        2022-05-10
 * @tags        tree, greedy
 * @difficulty  unknown
 */
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct Node {
  bool isLeaf = false;
  vector<int> children;
  int leafCnt = 0;
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector<vector<int>> adj(N+1);
  vector<Node> nodes(N+1);
  for (int i = 1, u, v; i < N; ++i) {
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }

  function<void(int,int)> dfsBuildTree = [&](int p, int u) {
    auto& node = nodes[u];
    for (int v : adj[u]) {
      if (v == p) continue;
      dfsBuildTree(u, v);
      node.children.push_back(v);
      node.leafCnt += nodes[v].leafCnt;
    }
    if (node.children.empty()) {
#ifdef DEBUG
      fprintf(stderr, "node %d is a leaf node\n", u);
#endif
      node.isLeaf = true, node.leafCnt = 1;
    }
  };
  dfsBuildTree(0, 1);

  vector<pair<int,int>> res;
  res.reserve(N);

  auto match = [&](unordered_map<int, vi>& leaves, int a, int b, int &t) {
    auto& A = leaves[a];
    auto& B = leaves[b];
    while (t >= 2 && !A.empty() && !B.empty()) {
#ifdef DEBUG
      fprintf(stderr, "matching %d -> %d\n", A.back(), B.back());
#endif
      res.emplace_back(A.back(), B.back());
      A.pop_back(), B.pop_back();
      t -= 2;
    }
    if (A.empty()) leaves.erase(a);
    if (B.empty()) leaves.erase(b);
  };

  function<vi(int)> getLeaves = [&](int v) {
    auto& node = nodes[v];
    if (node.isLeaf) return vi{v};

    vi res;
    for (int u : node.children) {
      auto L = getLeaves(u);
      res.insert(res.end(), L.begin(), L.end());
    }
    return res;
  };

  function<vi(int,int)> dfsMatch = [&](int u, int target) {
#ifdef DEBUG
      fprintf(stderr, "match %d at node %d\n", target, u);
#endif
    vector<pair<int,int>> matches;
    multimap<int,int> children;
    auto& node = nodes[u];
    if (target == 1) {
      auto leaves = getLeaves(u);
      res.emplace_back(u, leaves.back());
      leaves.pop_back();
      return leaves;
    }

    for (int v : node.children) {
      auto& child = nodes[v];
      children.emplace(child.leafCnt, v);
#ifdef DEBUG
      fprintf(stderr, "children.emplace(leaves=%d, node=%d)\n", child.leafCnt, v);
#endif
    }
    int t = target;
    while (children.size() > 1) {
      auto a = children.begin();
      auto b = prev(children.end());
      int c = b->second;
      int numMatched = min(min(a->first, b->first) * 2, t);
      int r = b->first + a->first - numMatched;
      matches.emplace_back(a->second, b->second);
#ifdef DEBUG
      fprintf(stderr, "matches.emplace_back(%d, %d)\n", a->second, b->second);
      fprintf(stderr, "matched=%d  r=%d\n", numMatched, r);
#endif
      children.erase(b), children.erase(a);
      if (r) children.emplace(r, c);
      t -= numMatched;
      if (t <= 0) break;
    }
    unordered_map<int, vi> leaves;
    if (!children.empty()) {
      auto itr = children.begin();
      auto v = itr->second;
      leaves.emplace(v, dfsMatch(v, itr->first)); // match out residual at next node
    }
    for (int v : node.children) {
      if (leaves.count(v)) continue;
      leaves[v] = getLeaves(v);
    }
    for (auto [a, b] : matches) match(leaves, a, b, target);
    if (leaves.empty()) return vi();
    auto& remain = leaves.begin()->second;
#ifdef DEBUG
    fprintf(stderr, "remaining leaves at node %d: ", u);
    for (int v : remain) cerr << v << ' ';
    cerr << endl;
#endif
    return remain;
  };
  dfsMatch(1, nodes[1].leafCnt);

  printf("%lu\n", res.size());
  for (auto [a,b] : res) printf("%d %d\n", a, b);
  return 0;
}
