#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using v2i = vector<vi>;
int INF = 1e9;
v2i G;

void debug(vi &V) {
  for (auto v : V) cout << v << " ";
  cout << endl;
}

void debug(vb &V) {
  for (auto v : V) cout << v << " ";
  cout << endl;
}

void debug(v2i &T) {
  for (auto &row : T) {
    for (auto cell : row) {
      if (cell != INF) cout << cell << " ";
      else cout << "I ";
    }
    cout << endl;
  }
}

void dfs(v2i &DG, vi &P, v2i &DP, int n, int t) {
  for (size_t i = 0; i < DG.size(); ++i) {
    if (DG[n][i] == INF) continue;
    dfs(DG, P, DP, i, DG[n][i]);
  }
  int p = P[n];
  if (p == -1) return;
  for (size_t i = DP[n].size() - 1; i >= t; --i) {
    DP[p][i] = max(
      DP[p][i],
      max(DP[n][i - t], DP[p][i - t]) + 1
    );
  }
  #if DEBUG
  printf("n: %d, t: %d\n", n, t);
  debug(DP[p]);
  #endif
}

int solve(vi &P, int _b, int n) {
  #if DEBUG
  printf("solving: %d\n", _b);
  #endif
  int a, b = _b, left = n, res = 0;
  vb S(P.size(), false);
  S[0] = true;
  queue<int> Q;
  while (b != 0) {
    S[b] = true;
    Q.push(b);
    a = P[b];
    left -= G[a][b];
    if (left < 0) return -1;
    ++res;
    b = a;
  }
  Q.push(0);
  int s = G.size();
  v2i DG(G.size() + 1, vi(G.size() + 1, INF));
  vi P2(DG.size(), -1);
  #if DEBUG
  debug(S);
  #endif
  while (!Q.empty()) {
    a = Q.front(); Q.pop();
    for (size_t i = 0; i < G.size(); ++i) {
      if (
        G[a][i] == INF || // no edge
        P2[i] != -1 || // visited
        S[i] // on stem
      ) continue;
      P2[i] = S[a] ? s : a;
      DG[P2[i]][i] = G[a][i] * 2;
      Q.push(i);
    }
  }
  #if DEBUG
  debug(DG);
  debug(P2);
  #endif
  v2i DP(DG.size(), vi(left + 1, 0));
  dfs(DG, P2, DP, s, 0);
  #if DEBUG
  printf("total: %d, left: %d\n", n, left);
  printf("on stem: %d, on blossom: %d\n", res, DP[s][left]);
  debug(DP);
  #endif
  return res + DP[s][left];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, a, b, t;
  cin >> m >> n;
  G.assign(m, vi(m, INF));
  for (int i = 1; i < m; ++i) {
    cin >> a >> b >> t;
    G[b][a] = G[a][b] = t;
  }
  queue<int> Q;
  Q.push(0);
  vi P(m, -1);
  int cur, res = 0;
  P[0] = 0;
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    #if DEBUG
    printf("bfs: %d\n", cur);
    #endif
    for (int i = 0; i < m; ++i) {
      if (G[cur][i] == INF || P[i] != -1) continue;
      P[i] = cur;
      res = max(res, solve(P, i, n));
      Q.push(i);
    }
  }
  cout << res << endl;
  return 0;
}
