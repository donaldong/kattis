#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

v2i G;
vi deg;

bool kahn(vi &ord) {
  queue<int> Q;
  for (int i = 1; i < G.size(); ++i) {
    if (!deg[i]) ord.push_back(i), Q.push(i);
  }
  int a;
  while (!Q.empty()) {
    a = Q.front(), Q.pop();
    for (int b : G[a]) {
      if (deg[b] == 0) continue;
      --deg[b];
      if (!deg[b]) ord.push_back(b), Q.push(b);
    }
  }
  return ord.size() + 1 == G.size();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  G.resize(n + 1), deg.assign(G.size(), 0);
  while (m--) {
    cin >> a >> b;
    G[a].push_back(b);
    ++deg[b];
  }
  vi ord;
  ord.reserve(G.size());
  if (kahn(ord)) for (int i : ord) printf("%d\n", i);
  else printf("IMPOSSIBLE\n");
  return 0;
}
