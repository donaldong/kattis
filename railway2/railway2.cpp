#include <bits/stdc++.h>
using namespace std;

int N, M, K;

struct edge {
  int a, b;
  int count = 0;
  edge() {}
  edge(int a, int b) : a(a), b(b) {}
  int from(int k) {
    return k == a ? b : a;
  }
};

using hsi = unordered_set<int>;
using ve = vector<edge*>;
using v2e = vector<ve>;
using vb = vector<bool>;

int COUNT;
ve E;
v2e NODES;
vb V;

bool dfs(hsi &S, int n) {
  if (V[n]) return false;
  V[n] = true;
  bool res = S.find(n) != S.end();
  for (auto e : NODES[n]) {
    int dest = e->from(n);
    if (dfs(S, dest)) {
      res = true;
      ++e->count;
      if (e->count >= K) ++COUNT;
    }
  }
  return res;
}

int main() {
  COUNT = 0;
  cin >> N >> M >> K;
  E = ve(N - 1);
  NODES = v2e(N);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    E[i] = new edge(a, b);
    NODES[a].push_back(E[i]);
    NODES[b].push_back(E[i]);
  }
  int s, e;
  for (int i = 0; i < M; ++i) {
    cin >> s;
    hsi S;
    while (s--) {
      cin >> e;
      --e;
      S.insert(e);
    }
    V = vb(N - 1, false);
    dfs(S, *S.begin());
  }
  cout << COUNT << endl;
  for (size_t i = 0; i < E.size(); ++i) {
    if (E[i]->count >= K) cout << i + 1 << " ";
  }
  cout << endl;
  return 0;
}
