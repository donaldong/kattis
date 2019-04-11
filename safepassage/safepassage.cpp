#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> tup;
int INF = 1e9;
vi DP, N;

int solve(int a) {
  int b, c, d, nd, f;
  priority_queue<tup, vector<tup>, greater<tup>> Q;
  Q.emplace(0, a), DP[a] = 0;
  while (!Q.empty()) {
    tie(d, a) = Q.top(), Q.pop();
    if (d > DP[a]) continue;
    for (int i = 0; i < N.size(); ++i) {
      if (a & (1 << i)) continue;
      for (int j = i + 1; j < N.size(); ++j) {
        if (a & (1 << j)) continue;
        b = a | (1 << i), b |= (1 << j);
        f = max(N[i], N[j]);
        if (b + 1 == DP.size()) {
          DP[b] = min(DP[b], d + f);
          continue;
        }
        for (int k = 0; k < N.size(); ++k) {
          if (!(b & (1 << k))) continue;
          nd = d + f + N[k], c = b ^ (1 << k);
          if (nd >= DP[c]) continue;
          DP[c] = nd, Q.emplace(nd, c);
        }
      }
    }
  }
  return DP.back();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  N.resize(n), DP.resize(1 << n, INF);
  for (auto &e : N) cin >> e;
  printf("%d\n", solve(0));
  return 0;
}
