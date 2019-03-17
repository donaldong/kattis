#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<vb> v2b;
vb used;
v2b G;

int solve(int n) {
  if (n == used.size()) return 1;
  int res = solve(n + 1);
  for (int i = 0; i < used.size(); ++i) {
    if (used[i] && G[n][i]) return res;
  }
  used[n] = true;
  res += solve(n + 1);
  used[n] = false;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  G.assign(n, vb(n, false));
  used.assign(n, false);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    G[a][b] = G[b][a] = true;
  }
  printf("%d\n", solve(0));
  return 0;
}
