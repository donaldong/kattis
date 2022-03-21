#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;

v2i E;

int bfs(queue<int> &Q, vi & vis) {
  int res = 0, n;
  while (!Q.empty()) {
    n = Q.front(); Q.pop();
    bool f = false;
    for (auto nxt : E[n]) {
#ifdef DEBUG
      printf("=> %d\n", nxt);
#endif
      if (nxt < 0) {
        f = true;
        nxt *= -1;
        if (vis[nxt]) continue;
        vis[nxt] = 2;
        Q.push(nxt);
      }
    }
    if (!f) ++res;
#ifdef DEBUG
    printf("node %d (%d)\n", n, res);
#endif
  }
  return res;
}

int bfs(int n) {
  queue<int> Q;
  vi vis(E.size(), 0);
  vis[n] = 2; Q.push(n);
  int res = bfs(Q, vis);
  for (size_t i = 1; i < vis.size(); ++i) {
    if (vis[i] == 2) {
      for (auto nxt : E[i]) {
        if (nxt < 0) nxt *= -1;
        if (!vis[nxt]) vis[nxt] = 1;
      }
    }
  }
  for (size_t i = 0; i < vis.size(); ++i) {
    if (vis[i] == 1) {
#ifdef DEBUG
      printf("+ %zu\n", i);
#endif
      Q.push(i);
    }
  }
  return res + bfs(Q, vis);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a, b;
  cin >> n >> m;

  E.resize(n + 1);
  while (m--) {
    cin >> a >> b;
    if (a < 0) a *= -1, b *= -1;
    E[a].push_back(b);
  }

  printf("%d\n", bfs(1));
  return 0;
}
