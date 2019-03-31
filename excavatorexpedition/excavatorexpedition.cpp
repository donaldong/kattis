#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
string X;
v2i G;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int v, e, a, b, d, nd;
  cin >> v >> e >> X;
  G.resize(v);
  while (e--) {
    cin >> a >> b;
    G[a].push_back(b);
  }
  vi D(v, INT_MIN);
  priority_queue<tuple<int, int>> Q;
  D[0] = 0, Q.emplace(0, 0);
  while (!Q.empty()) {
    tie(d, a) = Q.top(), Q.pop();
    for (int c : G[a]) {
      nd = d;
      if (c + 1 != v) {
        if (X[c] == 'X') ++nd;
        else --nd;
      }
      if (nd <= D[c]) continue;
      D[c] = nd, Q.emplace(nd, c);
    }
  }
  printf("%d\n", D.back());
  return 0;
}
