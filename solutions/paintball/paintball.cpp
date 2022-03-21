#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

vi match;
v2i G;

bool aug(int a, vi &vis) {
  if (vis[a]) return false;
  vis[a] = 1;
  for (int b : G[a]) {
    if (match[b] < 0 || aug(match[b], vis)) {
      match[b] = a;
      return true;
    }
  }
  return false;
}

int max_match(int n) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    vi vis(n + 1, 0);
    if (aug(i, vis)) ++res;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  G.resize(n + 1), match.assign(n + 1, -1);
  while (m--) {
    cin >> a >> b;
    G[a].push_back(b), G[b].push_back(a);
  }
  if (max_match(n) != n) return printf("Impossible\n"), 0;
  for (int i = 1; i <= n; ++i) printf("%d\n", match[i]);
  return 0;
}
