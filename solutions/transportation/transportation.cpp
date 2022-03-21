#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;
using hmap = unordered_map<string, int>;

hmap NAMES;

int index(string &s) {
  int res;
  if (NAMES.find(s) == NAMES.end()) {
    res = NAMES.size();
    NAMES[s] = res; 
    return res;
  }
  return NAMES[s];
}

bool bfs(v2i &G, int s, int t, vi &P) {
  vb V(G.size(), false);
  queue<int> Q;
  V[s] = true;
  Q.push(s);
  while (!Q.empty()) {
    int n = Q.front(); Q.pop();
    for (size_t i = 0; i < G.size(); ++i) {
      if (V[i] || G[n][i] <= 0) continue;
      V[i] = true;
      P[i] = n;
      Q.push(i);
    }
  }
  return V[t];
}

int max_flow(v2i &G, int s, int t) {
  int res = 0, a, b;
  // Parents / Matching
  vi P(G.size());
  while (bfs(G, s, t, P)) {
    ++res;
    for (b = t; b != s;) {
      a = P[b];
      G[a][b] -= 1;
      G[b][a] += 1;
      swap(a, b);
    }
  }
  return res;
}

v2i extend(v2i &G, int s, int t) {
  v2i R(G.size() + t, vi(G.size() + t, 0));
  for (size_t i = 0; i < s; ++i) {
    for (size_t j = s; j < G.size(); ++j) R[i][j] = G[i][j]; // copy nodes to colors
  }
  for (size_t i = 0; i < t; ++i) {
    for (size_t j = 0; j < G.size(); ++j) {
      R[i + G.size()][j] = G[s + i][j]; // copy colors to nodes to the new rows
    }
  }
  for (size_t i = G.size() - 2; i < G.size(); ++i) {
    for (size_t j = 0; j < G.size(); ++j) {
      R[i][j] = G[i][j]; // copy the sink and target
    }
  }
  for (size_t i = 0; i < t; ++i) {
    size_t a = i + s;
    size_t b = i + G.size();
    R[a][b] = R[b][a] = 1; // adding the color edge (undirected)
  }
  return R;
}

int main() {
  int s, r, f, t, n, k;
  string name;
  cin >> s >> r >> f >> t;
  k = s + t + 2;
  // Graph [nodes, colors, sink, target]
  v2i G(k, vi(k, 0));
  int sink = k - 2;
  for (int i = 0; i < r; ++i) {
    cin >> name;
    k = index(name);
    G[sink][k] = 1; // inf cap
  }
  for (int i = 0; i < f; ++i) {
    cin >> name;
    k = index(name);
    G[k][sink + 1] = 1;
  }
  for (int e = 0; e < t; ++e) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> name;
      k = index(name);
      G[k][s + e] = G[s + e][k] = 1; // undirected
    }
  }
  // [nodes, colors, sink, target, ext colors (the other end)]
  G = extend(G, s, t);  // adding edge cap of 1 for all colors
  cout << max_flow(G, sink, sink + 1) << endl;
  return 0;
}
