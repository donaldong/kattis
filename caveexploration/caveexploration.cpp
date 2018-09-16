#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;

bool possible(v2i &G, int n, int p, vi &S) {
  queue<int> Q;
  for (int c : G[n]) if (c != p) {
    if (S[c] == 1) return true;
    Q.push(c);
  }
  vb V(G.size(), false);
  V[n] = true;
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for (int c : G[cur]) {
      if (S[c] == 1) return true;
      if (V[c]) continue;
      V[c] = true;
      Q.push(c);
    }
  }
  return false;
}

int solve(v2i &G) {
  vi S(G.size(), -1);
  S[0] = 1;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for (int n : G[cur]) {
      if (S[n] != -1) continue;
      // n -> cur without using cur -> n
      if (possible(G, n, cur, S)) {
        S[n] = 1;
        Q.push(n);
      } else S[n] = 0;
    }
  }
  int res = 0;
  for (int s : S) if (s == 1) ++res;
  return res;
}

int main() {
  int n, m, a, b;
  cin >> n >> m;
  v2i G(n);
  while (m--) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cout << solve(G) << endl;
  return 0;
}
