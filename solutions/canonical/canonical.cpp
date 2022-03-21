#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int V, INF = 1e9;
vi N, DP, greedy;

bool counter() {
  DP[0] = 0, greedy[0] = 0;
  int j = 0;
  for (int i = 1; i < V; ++i) {
    while (j + 1 < N.size() && N[j + 1] <= i) ++j;
    greedy[i] = greedy[i - N[j]] + 1;
    for (int n : N) if (i >= n) {
      DP[i] = min(DP[i], DP[i - n] + 1);
    } else break;
    if (DP[i] == INF) continue;
    if (DP[i] != greedy[i]) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  N.resize(n);
  for (auto &e : N) cin >> e;
  V = N[n - 1] + N[n - 2] + 1, DP.assign(V, INF), greedy.resize(V);
  printf("%s\n", counter() ? "non-canonical" : "canonical");
  return 0;
}
