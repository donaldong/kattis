#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> v2i;

vs S;
vi vis, deg;
v2i T;

void dfs(int n) {
  if (vis[n]) return;
  vis[n] = true;
  printf("%s", S[n].c_str());
  for (int nn : T[n]) dfs(nn);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, a, b;
  cin >> n;
  S.resize(n), vis.assign(n, 0), T.resize(n);
  deg = vis;
  for (int i = 0; i < n; ++i) cin >> S[i];
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    --a, --b;
    T[a].push_back(b);
    ++deg[b];
  }
  for (int i = 0; i < n; ++i) if (!deg[i]) {
    dfs(i);
    break;
  }
  printf("\n");
  return 0;
}
