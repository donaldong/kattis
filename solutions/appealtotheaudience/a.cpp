/**
 * @date        2022-03-25
 * @tags        dfs, greedy, tree
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
struct Node {
  vector<int> children;
  int parent = -1, level = 0, winner = -1;
};
vector<Node> N;
vector<int> K;

void dfs(int u) {
  for (int v : N[u].children) {
    dfs(v);
    if (N[v].level+1 <= N[u].level) continue;
    N[u].level = N[v].level+1;
    N[u].winner = N[v].winner;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, k;
  cin >> n >> k;
  N.resize(n);
  K.resize(k);
  for (auto& v : K) cin >> v;
  for (int i = 1, p; i < n; ++i) {
    cin >> p;
    N[p].children.push_back(i);
    N[i].winner = i, N[i].parent = p;
  }

  dfs(0);
  vector<int> L;
  L.reserve(K.size());
  for (int i = 0; i < n; ++i) {
    if (!N[i].children.empty()) continue;
    int l = 0;
    for (int j = i; j != -1 && N[j].winner == i; j = N[j].parent) ++l;
    L.push_back(l);
  }

  long long res = 0;
  sort(K.rbegin(), K.rend());
  sort(L.rbegin(), L.rend());
  for (int i = 0; i < K.size(); ++i) {
    res += (long long)K[i]*L[i];
  }
  res -= K[0];
  cout << res << endl;
  return 0;
}
