#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using v2i = vector<vi>;

void bfs(v2i &G, int cur, vb &V) {
  queue<int> Q;
  Q.push(cur);
  V[cur] = true;
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    for (auto nxt : G[cur]) {
      if (V[nxt]) continue;
      V[nxt] = true;
      Q.push(nxt);
    }
  }
}

int main() {
  int t, n, m, l, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> m >> l;
    vb V(n, false);
    v2i G(n);
    while (m--) {
      cin >> a >> b;
      --a, --b;
      G[a].push_back(b);
    }
    while (l--) {
      cin >> a;
      bfs(G, --a, V);
    }
    int res = 0;
    for (auto v : V) if (v) ++res;
    cout << res << endl;
  }
  return 0;
}
