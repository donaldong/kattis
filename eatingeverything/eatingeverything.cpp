#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vf = vector<double>;
using v2f = vector<vf>;
using vb = vector<bool>;

int N, MAX_STEP = 39;
vi C;
v2i G;
v2f DP;
vb vis;

void dfs(int a, int b) {
  if (!vis[b]) for (int c : G[b]) dfs(b, c);
  if (a != -1) for (int i = 1; i < MAX_STEP; ++i) {
    DP[a][i] = max(
      max(max(DP[a][i - 1], DP[a][i]), DP[b][i]),
      DP[b][i - 1] / 2.0 + C[a]
    );
  }
  vis[b] = true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, a, b;
  cin >> N >> m;
  C.resize(N), G.resize(N);
  DP.assign(N, vf(MAX_STEP, 0.0)), vis.assign(N, false);
  for (auto &c : C) cin >> c;
  while (m--) {
    cin >> a >> b;
    G[a].push_back(b);
  }

  for (int i = 0; i < N; ++i) DP[i][1] = C[i];
  dfs(-1, 0);
  printf("%.7lf\n", *max_element(DP[0].begin(), DP[0].end()));
  return 0;
}
