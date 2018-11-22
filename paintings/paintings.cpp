#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;
using vb = vector<bool>;
using v2b = vector<vb>;

int solve(v2b &G, vb &vis, int n, vi &S, int k, bool &found) {
  if (vis[n]) return 0;
  if (k == G.size()) {
    if (!found) found = true, S.push_back(n);
    return 1;
  }
  vis[n] = true;
  if (!found) S.push_back(n);
  int res = 0;
  for (size_t c = 0; c < G.size(); ++c) {
    if (c == n || !G[n][c]) continue;
    res += solve(G, vis, c, S, k + 1, found);
  }
  vis[n] = false;
  if (!found) S.pop_back();
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n;
    unordered_map<string, int> M;
    vs cols(n);
    for (int i = 0; i < n; ++i) {
      cin >> cols[i];
      M[cols[i]] = i;
    }
    v2b G(n, vb(n, true));
    vb vis(n, false);
    cin >> m;
    string a, b;
    while (m--) {
      cin >> a >> b;
      int i = M[a], j = M[b];
      G[i][j] = G[j][i] = false;
    }
    int res = 0;
    vi S;
    bool found = false;
    for (auto col : cols) res += solve(G, vis, M[col], S, 1, found);
    printf("%d\n", res);
    for (int i = 0; i < n; ++i) {
      if (i) printf(" ");
      printf("%s", cols[S[i]].c_str());
    }
    printf("\n");
  }
  cout << flush;
  return 0;
}
