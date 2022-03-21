#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

v2i G;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k, tot, res = 0;
  string s;
  cin >> n >> k;
  tot = 1 << k;
  G.resize(tot);
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < k; ++j) {
      G[i].push_back(i ^ (1 << j));
    }
  }
  queue<int> Q;
  vi vis(tot, 0);
  while (n--) {
    cin >> s;
    int v = 0;
    for (char c : s) v = 2 * v + c - '0';
    Q.push(v), vis[v] = 1;
  }
  while (!Q.empty()) {
    res = Q.front(), Q.pop();
    for (int nn : G[res]) if (!vis[nn]) vis[nn] = 1, Q.push(nn);
  }
  for (int i = k; i--;) printf("%c", (res & (1 << i)) ? '1' : '0');
  printf("\n");
  return 0;
}
