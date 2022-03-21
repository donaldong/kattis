#include <bits/stdc++.h>
using namespace std;
struct Solution {
  vector<vector<int>> adj;
  vector<int> level;
  vector<int> tin, tout;
  vector<vector<int>> up;
  int timer, l;

  Solution() {
    int n, a, b;
    cin >> n;
    adj.resize(n);
    level.resize(n);
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
		for (int i = 1; i < n; ++i) {
			cin >> a >> b;
      --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(0, 0, 0);
  }

	void dfs(int v, int p, int d) {
#ifdef DEBUG
    printf("dfs(%d,%d,%d)\n", v, p, d);
#endif
		tin[v] = ++timer;
		up[v][0] = p;
    level[v] = d;
		for (int i = 1; i <= l; ++i)  up[v][i] = up[up[v][i-1]][i-1];

		for (int u : adj[v]) {
			if (u != p) dfs(u, v, d + 1);
		}

		tout[v] = ++timer;
	}

	bool is_ancestor(int u, int v)
	{
			return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int lca(int u, int v)
	{
			if (is_ancestor(u, v))
					return u;
			if (is_ancestor(v, u))
					return v;
			for (int i = l; i >= 0; --i) {
					if (!is_ancestor(up[u][i], v))
							u = up[u][i];
			}
			return up[u][0];
	}


  int dist(int a, int b) {
#ifdef DEBUG
    printf("dist(%d,%d)\n", a, b);
#endif
    int c = lca(a, b);
    if (c == a || c == b) return abs(level[a]-level[b]);
    return abs(level[a]-level[c])+abs(level[b]-level[c]);
  }

  bool valid() {
    int a, b;
    cin >> a;
    --a;
    bool res = true;
    for (int i = 1; i < adj.size(); ++i) {
      cin >> b;
      --b;
      if (dist(a, b) > 3) res = false;
      a = b;
    }
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    Solution s;
    cout << s.valid() << endl;
  }
  return 0;
}
