#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi X, Y, R, col;

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

bool reach(int a, int b) {
  int dx = X[a] - X[b], dy = Y[a] - Y[b];
  int r = R[a] + R[b];
  return dx * dx + dy * dy == r * r;
}

void dfs(int n, bool c) {
  col[n] = c;
  for (size_t i = 0; i < X.size(); ++i) {
    if (col[i] != -1 || !reach(n, i)) continue;
    dfs(i, !c);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n, p, q, k;
  cin >> t;
  while (t--) {
    cin >> n;
    X.resize(n), Y.resize(n), R.resize(n), col.assign(n, -1);
    for (int i = 0; i < n; ++i) cin >> X[i] >> Y[i] >> R[i];
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
      if (col[i] < 0) printf("not moving\n");
      else {
        p = R[0], q = R[i], k = gcd(p, q);
        if (k == q) printf("%d", p / q);
        else printf("%d/%d", p / k, q / k);
        printf(" %s\n", col[i] ? "counterclockwise" : "clockwise");
      }
    }
  }
  return 0;
}
