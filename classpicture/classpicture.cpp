#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<string> vs;
vb vis;

bool solve(const v2i &G, int n, vi &res) {
  for (int c : G[n]) {
    if (!res.empty() && res.back() == c) return false;
  }
  vis[n] = true;
  res.push_back(n);
  if (res.size() == G.size()) return true;
  for (int i = 0; i < G.size(); ++i) {
    if (vis[i]) continue;
    if (solve(G, i, res)) return true;
  }
  vis[n] = false;
  res.pop_back();
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  string a, b;
  while (cin >> n) {
    vs N(n);
    for (auto &e : N) cin >> e;
    sort(N.begin(), N.end());
    unordered_map<string, int> ID;
    for (int i = 0; i < n; ++i) ID[N[i]] = i;
    v2i G(n);
    cin >> m;
    while (m--) {
      cin >> a >> b;
      int i = ID[a], j = ID[b];
      G[i].push_back(j), G[j].push_back(i);
    }
    vis.assign(n, false);
    bool solved = false;
    for (int i = 0; i < n; ++i) {
      vi res;
      if (solve(G, i, res)) {
        for (int r : res) printf("%s ", N[r].c_str());
        solved = true;
        break;
      }
    }
    if (!solved) printf("You all need therapy.");
    printf("\n");
  }
  return 0;
}
