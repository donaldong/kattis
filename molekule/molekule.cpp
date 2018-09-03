#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b;
  int col = -1;
  edge() {}
  edge(int a, int b) : a(a), b(b) {}
};

using ve = vector<edge*>;
using v2e = vector<ve>;

v2e N;
ve E;

int get_dest(edge *e, int src) {
  if (e->a == src) return e->b;
  return e->a;
}

void dfs(int n, bool f) {
  for (auto e : N[n]) {
    if (e->col != -1) continue;
    int dest = get_dest(e, n);
    if (e->b == dest) e->col = 1;
    else e->col = 0;
    if (f) e->col = !e->col;
    dfs(dest, !f);
  }
}

int main() {
  int n;
  cin >> n;
  N = v2e(n);
  E = ve(n - 1);
  for (size_t i = 0; i < E.size(); ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    E[i] = new edge(a, b);
    N[a].push_back(E[i]);
    N[b].push_back(E[i]);
  }
  dfs(0, false);
  for (auto e : E) cout << e->col << endl;
  return 0;
}
