#include <bits/stdc++.h>
using namespace std;

struct node;
using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;
vi P; // parents
v2i N, B; // nodes, bottoms for each top
vb M, A; // mark array, tops

void mark(int n) {
  M[n] = true;
  for (int c : N[n]) if (!M[c]) mark(c);
}

int dfs(int n) {
  int res = 0;
  for (int c : N[n]) {
    res += dfs(c);
  }
  if (!A[n]) return res;
  bool f = false;
  for (int b : B[n]) if (!M[b]) {
    f = true; break;
  }
  mark(n);
  return res + f;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, m, a, b;
  cin >> n >> k >> m;
  N.resize(n);
  P.assign(n, -1);
  while (k--) {
    cin >> a >> b;
    --a, --b;
    N[a].push_back(b);
    P[b] = a;
  }
  A.assign(n, false), B.resize(n);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    A[a] = true;
    B[a].push_back(b);
  }
  int res = 0;
  M.assign(n, false);
  for (int i = 0; i < n; ++i) if (P[i] == -1) res += dfs(i);
  cout << res << endl;
  return 0;
}
