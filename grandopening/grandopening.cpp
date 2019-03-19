#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (i = a; i < b; ++i)
typedef unordered_map<string, int> hmap;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> v2i;

hmap ID;
vb vis;
vi ord, IN, OUT;
v2i G, GT;

int id(const string &s) {
  auto itr = ID.find(s);
  if (itr != ID.end()) return itr->second;
  size_t k = ID.size();
  ID[s] = k;
  G.push_back(vi());
  GT.push_back(vi());
  return k;
}

void dfs_search(int n) {
  vis[n] = true;
  for (int c : G[n]) if (!vis[c]) dfs_search(c);
  ord.push_back(n);
}

void dfs_fill(int n) {
#ifdef DEBUG
    printf("fill: %d\n", n);
#endif
  vis[n] = true;
  for (int c : GT[n]) {
    if (!vis[c]) dfs_fill(c);
  }
}

bool solve() {
  int a = -1, b = -1;
  for (size_t i = 0; i < G.size(); ++i) {
    if (IN[i] != OUT[i]) {
      if (a < 0 && IN[i] + 1 == OUT[i]) a = i;
      else if (b < 0 && IN[i] == OUT[i] + 1) b = i;
      else return false;
    }
  }

  if (a >= 0 && b >= 0) {
    G[b].push_back(a);
    GT[a].push_back(b);
    ++IN[a], ++OUT[b];
  }

  vis.assign(G.size(), false);
  for (size_t i = 0; i < vis.size(); ++i) {
    if (!vis[i]) dfs_search(i);
  }

  vis.assign(G.size(), false);
  int deg, k;
  while (!ord.empty()) {
    k = ord.back();
    deg = IN[k] + OUT[k];
    if (deg) break;
    ord.pop_back();
  }
  dfs_fill(k);

  for (size_t i = 0; i < G.size(); ++i) {
    deg = IN[i] + OUT[i];
    if (!deg) continue;
    if (!vis[i] || IN[i] != OUT[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, k, a, b;
  string A, B;
  cin >> n >> m;
  ord.reserve(n);
  IN.assign(n, 0), OUT = IN;
  bool f = true;
  rep(i, 0, n) {
    cin >> A >> k;
    a = id(A);
    rep(j, 0, k) {
      cin >> B;
      b = id(B);
      if (A == B) continue;
      G[a].push_back(b);
      GT[b].push_back(a);
#ifdef DEBUG
      printf("%d %d\n", a, b);
#endif
      ++OUT[a], ++IN[b];
      f = false;
    }
  }
  if (f) printf("FALSE ALARM\n");
  else printf("%s\n", solve() ? "POSSIBLE" : "IMPOSSIBLE");
  return 0;
}
