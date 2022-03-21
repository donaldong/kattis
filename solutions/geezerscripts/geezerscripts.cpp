#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct edge {
  int to, a, h;
};

int calc(int h1, int a1, int h2, int a2) {
  long long k = h2 / a1;
  if (h2 % a1) ++k;
  --k;
  if (k < 0) k = 0;
  k *= a2;
  if (k > h1) return 0;
  return h1 - k;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int A, H, n, m, i, j, a, h, nh;
  cin >> A >> H >> n >> m;
  vector<vector<edge>> G(n);
  while (m--) {
    cin >> i >> j >> a >> h;
    G[i - 1].push_back({j - 1, a, h});
  }

  vi D(n, 0);
  priority_queue<tuple<int, int>> Q;
  D[0] = H, Q.emplace(H, 0);
  while (!Q.empty()) {
    tie(h, i) = Q.top(), Q.pop();
    if (h < D[i]) continue;
    for (auto &e : G[i]) {
      nh = calc(h, A, e.h, e.a);
      if (nh <= D[e.to]) continue;
      D[e.to] = nh, Q.emplace(nh, e.to);
    }
  }

  if (!D[n - 1]) printf("Oh no\n");
  else printf("%d\n", D[n - 1]);
  return 0;
}
