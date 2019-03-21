#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, int> hmap;
typedef vector<uint> vi;
typedef vector<vi> v2i;

bool valid(const vi &vis) {
  for (auto e : vis) if (!e) return false;
  return true; 
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  uint i, j, k;
  uint n, m, c, d, res = 0;
  string a, b;
  cin >> n >> m;
  hmap ID;
  for (i = 1; i <= n; ++i) {
    cin >> a; ID[a] = i;
  }
  v2i G(n + 1), C(n + 1);
  while (m--) {
    cin >> a >> b >> c;
    i = ID[a], j = ID[b];
    G[i].push_back(j), G[j].push_back(i);
    C[i].push_back(c), C[j].push_back(c);
  }
  vi vis(n + 1, 0);
  priority_queue<tuple<uint, uint, uint>> Q;
  Q.emplace(0, 0, 0);
  while (!Q.empty()) {
    tie(d, c, i) = Q.top(), Q.pop();
    if (vis[i]) continue;
    vis[i] = true;
    d *= -1, c *= -1;
#ifdef DEBUG
    printf("%u %u %u\n", d, c, i);
#endif
    res += c;
    for (k = 0; k < G[i].size(); ++k) {
      uint j = G[i][k];
      if (vis[j]) continue;
      Q.emplace(-(d + 1), -C[i][k], j);
    }
  }

  if (!valid(vis)) printf("Impossible\n");
  else printf("%u\n", res);
  return 0;
}
