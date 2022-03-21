#include <bits/stdc++.h>
using namespace std;

struct node;

using vn = vector<node*>;

struct node {
  vn neigh;
  int col = -1;
};

void dfs(node *n, int col) {
  if (n->col != -1) return;
  n->col = col;
  for (auto c : n->neigh) dfs(c, !col) ;
}

bool solve(vector<node> &N) {
  for (auto &n : N) if (n.neigh.empty()) return false;
  for (auto &n : N) if (n.col == -1) dfs(&n, 0);
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<node> N(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    N[a].neigh.push_back(&N[b]);
    N[b].neigh.push_back(&N[a]);
  }
  if (!solve(N)) cout << "Impossible";
  else for (auto &n : N) {
    if (n.col == 0) cout << "pub";
    else cout << "house";
    cout << " ";
  }
  cout << endl;
  return 0;
}
