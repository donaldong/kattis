#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;
using v2i = vector<vi>;
using hmap = unordered_map<string, int>;

bool dfs(v2i &G, vi &C, int n, bool col) {
  if (C[n] != -1) return C[n] != col;
  C[n] = col;
  for (int i : G[n]) {
    if (dfs(G, C, i, !col)) return true;
  }
  return false;
}

bool has_cycle(v2i &G, vi &C) {
  for (size_t i = 0; i < C.size(); ++i) {
    if (C[i] != -1) continue;
    if (dfs(G, C, i, 0)) return true;
  }
  return false;
}

int main() {
  int n, m, ra, rb;
  string a, b;
  cin >> n;
  vs N(n);
  v2i G(n);
  hmap M;
  for (int i = 0; i < n; ++i) {
    cin >> N[i];
    M[N[i]] = i;
  }
  cin >> m;
  while (m--) {
    cin >> a >> b;
    ra = M[a], rb = M[b];
    G[ra].push_back(rb);
    G[rb].push_back(ra);
  }
  vi C(n, -1);
  if (has_cycle(G, C)) cout << "impossible" << endl;
  else {
    for (int i = 0; i < n; ++i) {
      if (!C[i]) cout << N[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      if (C[i]) cout << N[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
