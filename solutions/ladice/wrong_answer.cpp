#include <bits/stdc++.h>
using namespace std;
vector<int> L;
vector<unordered_set<int>> vis;
vector<array<int, 2>> P;

bool dfs(int i, int d) {
  int& j = L[P[i][d]];
  if (vis[i].count(j)) return false;
  if (j >= 0) vis[i].insert(j);
  if (j < 0 || dfs(j, P[i][d] == P[j][0] ? 1 : 0)) {
    j = i;
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  L.assign(l+1, -1);
  vis.resize(n);
  P.reserve(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    P.push_back({a, b});
    bool res = false;

    if (L[a] < 0) {
      res = true;
      L[a] = i;
    } else if (L[b] < 0) {
      res = true;
      L[b] = i;
    }
    res = res || dfs(i, 0);
    res = res || dfs(i, 1);

    cout << (res ? "LADICA" : "SMECE") << endl;
  }
#ifdef DEBUG
  for (int i : L) cout << i << ' ';
  cout << endl;
#endif
  return 0;
}
