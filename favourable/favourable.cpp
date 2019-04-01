#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vl;
typedef vector<vi> v2i;

unordered_map<string, int> ID;
vl DP;
v2i G;
vi vis, ord;

int id(const string &s) {
  if (ID.find(s) != ID.end()) return ID[s];
  int res = ID.size();
  ID[s] = res;
  return res;
}

void dfs(int n) {
  if (vis[n]) return;
  vis[n] = true;
  for (int nn : G[n]) {
#ifdef DEBUG
    printf("%d => %d\n", n, nn);
#endif
    dfs(nn);
  }
  ord.push_back(n);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string line, tok;
  int t, s, a;
  getline(cin, line), t = stoi(line);
  while (t--) {
    getline(cin, line), s = stoi(line);
    G.assign(s, vi()), ID.clear(), ord.clear();
    DP.assign(s, 0), vis.assign(s, 0), ID["1"] = 0;
    vi col(s, -1);
    for (int i = 0; i < s; ++i) {
      getline(cin, line);
      stringstream ss(line);
      vs toks;
      while (getline(ss, tok, ' ')) toks.push_back(tok);
      if (toks.size() == 2) {
        col[id(toks[0])] = toks[1][0] != 'f'; // favourably
      } else {
        a = id(toks[0]);
        for (int i = 1; i < toks.size(); ++i) G[a].push_back(id(toks[i]));
      }
#ifdef DEBUG
      printf("%s: %d\n", toks[0].c_str(), id(toks[0]));
#endif
    }
    ull res = 0;
    DP[0] = 1, dfs(0);
    for (int i = s; i--;) {
      a = ord[i];
      for (int b : G[a]) DP[b] += DP[a];
    }
#ifdef DEBUG
    for (int i = 0; i < s; ++i) cout << ord[i] << ' ';
    cout << endl;
    for (int i = 0; i < s; ++i) cout << DP[i] << ' ';
    cout << endl;
#endif
    for (int i = 0; i < s; ++i) if (!col[i]) res += DP[i];
    printf("%llu\n", res);
  }
  return 0;
}
