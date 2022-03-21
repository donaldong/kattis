#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  using Mat = vector<vector<int>>;
  Mat adj;
  int t;
  vector<int> tin, low;

  Solution(Mat&& adj) : adj(move(adj)) {}

  bool dfs(int i, int p) {
    low[i] = tin[i] = t++;
    for (int j : adj[i]) {
      if (j == p) continue;
      if (tin[j]) low[i] = min(low[i], tin[j]);
      else {
        if (dfs(j, i)) return true;
        if (low[j] > tin[i]) return true;
        low[i] = min(low[i], low[j]);
      }
    }
#ifdef DEBUG
    printf("low[%d]=%d\n",i,low[i]);
#endif
    return false;
  }

  bool hasBridge() {
    t = 1;
    tin.assign(adj.size(), 0);
    low.assign(adj.size(), INT_MAX);
    bool seen = false;
    if (dfs(0, -1)) return true;
    for (int i = 0; i < adj.size(); ++i) {
      if (!tin[i]) return true;
    }
    return false;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int p, c;
  while (cin >> p >> c) {
    if (!p || !c) break;
    vector<vector<int>> adj(p);
    while (c--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    Solution s(move(adj));
    printf("%s\n", s.hasBridge() ? "Yes" : "No");
  }
  return 0;
}
