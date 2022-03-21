#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;

bool match(v2i &G, int i, vi &P, vb &V) {
  for (int j : G[i]) {
    if (V[j]) continue;
    V[j] = true;
    if (P[j] == -1 || match(G, P[j], P, V)) {
      P[j] = i;
      return true;
    }
  }
  return false;
}

bool solve(v2i &G) {
  size_t res = 0;
  vi P(G.size(), -1);
  for (size_t i = 0; i < G.size(); ++i) {
    vb V(G.size(), false);
    if (!match(G, i, P, V)) return false; 
  }
  return true;
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  v2i G(n);
  while (m--) {
    cin >> a >> b;
    G[a].push_back(b);
  }
  cout << (solve(G) ? "YES" : "NO") << endl;
  return 0;
}
