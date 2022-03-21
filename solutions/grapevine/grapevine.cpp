#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

struct node {
  int c;
  vi adj;
};

using vn = vector<node>;
using hmap = unordered_map<string, int>;
hmap M;
vn N;

int bfs(int cur, int D) {
  vi C(N.size(), 1);
  vb V(N.size(), false);
  // node, day
  queue<tuple<int, int>> Q;
  Q.emplace(cur, 0);
  V[cur] = true;
  int d;
  while (!Q.empty()) {
    tie(cur, d) = Q.front(); Q.pop();
    if (d == D) continue;
    for (int nxt : N[cur].adj) {
      ++C[nxt];
      if (C[nxt] >= N[nxt].c && !V[nxt]) {
        V[nxt] = true;
        Q.emplace(nxt, d + 1);
      }
    }
  }
  int res = 0;
  for (auto v : V) if (v) ++res;
  return res - 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, d, a, b;
  string A, B;
  cin >> n >> m >> d;
  N.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> A >> N[i].c;
    M[A] = i;
  }
  while (m--) {
    cin >> A >> B;
    a = M[A], b = M[B];
    N[a].adj.push_back(b);
    N[b].adj.push_back(a);
  }
  cin >> A;
  cout << bfs(M[A], d) << endl;
  return 0;
}
