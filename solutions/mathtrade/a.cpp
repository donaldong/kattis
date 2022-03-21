#include <bits/stdc++.h>
using namespace std;
int N;
unordered_map<string, string> G;
unordered_map<string, int> tin, len;

int dfs(const string& u, int t) {
  if (len.count(u)) return len[u];
#ifdef DEBUG
  cout<< u << ' ' << t << endl;
#endif
  tin[u] = t;
  if (!G.count(u)) return len[u] = 0;
  auto& v = G[u];
  if (tin.count(v) && tin[v] < t) return len[u] = t-tin[v]+1;
  return len[u] = dfs(v, t+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string name, a, b;
    cin >> name >> a >> b;
    G[b] = a;
  }
  int res = 0;
  for (auto& [u, v] : G) {
    res = max(res, dfs(u, 0));
  }
  if (!res) cout << "No trades possible" << endl;
  else cout << res << endl;
  return 0;
}
