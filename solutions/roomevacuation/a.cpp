/**
 * @date        2023-02-05
 * @tags        graph, max flow
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
struct edge;
struct node {
  edge* back_edge = nullptr;
  vector<edge*> E;
};
struct edge {
  int flow;
  node* dest = nullptr;
  edge* rev = nullptr;
  edge() {}
  edge(int flow, node* dest) : flow(flow), dest(dest) {}
};

void add_edge(node& a, node& b) {
  a.E.push_back(new edge(1, &b));
  b.E.push_back(new edge(0, &a));
  a.E.back()->rev = b.E.back();
  b.E.back()->rev = a.E.back();
}

bool bfs(node* s, node* t) {
  unordered_set<node*> vis;
  queue<node*> q;
  q.push(s), vis.insert(s);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto e : u->E) {
      auto v = e->dest;
      if (vis.count(v) || e->flow <= 0) continue;
      v->back_edge = e->rev;
      if (v == t) return true;
      q.push(v), vis.insert(v);
    }
  }
  return false;
}

int ford_fulkerson(node* s, node* t) {
  int max_flow = 0;
  while (bfs(s, t)) {
    int path_flow = INT_MAX;
    for (auto v = t; v != s; v = v->back_edge->dest) {
      v->back_edge->rev->flow -= 1;
      v->back_edge->flow += 1;
    }
    ++max_flow;
  }
  return max_flow;
}

using vn = vector<node>;
using v2n = vector<vn>;
using v3n = vector<v2n>;
using v4n = vector<v3n>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, m, t;
  cin >> n >> m >> t;
  v4n nodes(n, v3n(m, v2n(t+1, vn(2))));
  vector<string> grid(n);
  for (auto& row : grid) cin >> row;
  vector<int> dir{0, -1, 0, 1, 0};
  node source, sink;
  for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
    if (grid[r][c] == '#') continue;
    if (grid[r][c] == 'E') {
      for (int i = 1; i <= t; ++i) {
        add_edge(nodes[r][c][i][0], nodes[r][c][i][1]);
        add_edge(nodes[r][c][i][1], sink);
      }
      continue;
    }
    if (grid[r][c] == 'P') add_edge(source, nodes[r][c][0][0]);
    for (int i = 0; i < t; ++i) {
      add_edge(nodes[r][c][i][0], nodes[r][c][i][1]);
      for (int d = 0; d < 4; ++d) {
        int r2 = r + dir[d], c2 = c + dir[d+1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
        if (grid[r2][c2] == '#') continue;
        add_edge(nodes[r][c][i][1], nodes[r2][c2][i+1][0]);
      }
      add_edge(nodes[r][c][i][1], nodes[r][c][i+1][0]); // stay still
    }
  }
  cout << ford_fulkerson(&source, &sink) << endl;
  return 0;
}
