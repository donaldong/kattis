#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int c, p, x ,l, a, b;
  cin >> c >> p >> x >> l;
  --x, --l;

  v2i G(c);
  vi deg(c, 0);
  while (p--) {
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b), G[b].push_back(a);
    ++deg[b], ++deg[a];
  }

  queue<int> Q;
  Q.push(l), deg[l] = 0;
  while (!Q.empty()) {
    a = Q.front(), Q.pop();
    for (int b : G[a]) {
      if (!deg[b]) continue;
      --deg[b];
      if (deg[b] * 2 <= G[b].size()) {
        deg[b] = 0, Q.push(b);
      }
    }
  }

  printf("%s\n", deg[x] ? "stay" : "leave");
  return 0;
}
