#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
vs G;

bool blank(int c) {
  for (size_t i = 0; i < G.size(); ++i) {
    if (G[i][c] != '_') return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  G.resize(n);
  for (auto &row : G) cin >> row;
  int res = 1;
  for (int i = 0; i < m; ++i) {
    if (blank(i)) ++res;
  }
  printf("%d\n", res);
  return 0;
}
