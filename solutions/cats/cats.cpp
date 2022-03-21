#include <bits/stdc++.h>
using namespace std;

typedef vector<uint> vi;
typedef vector<vi> v2i;
typedef tuple<uint, uint> tup;

v2i G;

uint mst() {
  uint res = 0, a, b, d;
  vi vis(G.size(), 0);
  priority_queue<tup, vector<tup>, greater<tup>> Q;
  Q.emplace(0, 0);
  while (!Q.empty()) {
    tie(d, a) = Q.top(), Q.pop();
    if (vis[a]) continue;
    vis[a] = 1, res += d;
    for (b = 0; b < G.size(); ++b) {
      if (vis[b]) continue;
      Q.emplace(G[a][b], b);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  uint T, M, C, a, b, d;
  cin >> T;
  while (T--) {
    cin >> M >> C;
    G.assign(C, vi(C));
    for (int i = C * (C - 1) / 2; i--;) {
      cin >> a >> b >> d;
      G[a][b] = G[b][a] = d;
    }
    printf("%s\n", mst() + C <= M ? "yes" : "no");
  }
  return 0;
}
