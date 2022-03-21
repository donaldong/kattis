#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

v2i T;
vi vis, D;
int d;

int solve(int n) {
  int res = 0, a = -1, b = -1, c;
  for (int nn : T[n]) {
    if (!vis[nn]) {
      vis[nn] = 1;
      c = solve(nn);
      if (c > b) b = c;
      if (b > a) swap(a, b);
      res = max(res, a + 1);
      d = max(d, a + b + 2);
    }
  }
  return res;
}

int rad(int d) {
  int res = d / 2;
  if (d & 1) ++res;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  T.resize(n), vis.assign(n, 0), D.reserve(n);
  while (m--) {
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) d = 0, vis[i] = 1, D.push_back(max(d, solve(i)));
  }
  sort(D.rbegin(), D.rend());
  int res = D[0];
  if (D.size() >= 2) res = max(res, rad(D[0]) + rad(D[1]) + 1);
  if (D.size() >= 3) res = max(res, rad(D[1]) + rad(D[2]) + 2);
  printf("%d\n", res);
  return 0;
}
