#include <bits/stdc++.h>
using namespace std;

typedef tuple<double, int> tup;

int N;
vector<double> X, Y;
vector<int> vis;

double dist(int a, int b) {
  double dx = X[a] - X[b];
  double dy = Y[a] - Y[b];
  return sqrt(dx * dx + dy * dy);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, a, b;
  double d, res;
  cin >> T;
  while (T--) {
    cin >> N;
    X.resize(N), Y.resize(N), vis.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    priority_queue<tup, vector<tup>, greater<tup>> Q;
    Q.emplace(0, 0), res = 0.0;
    while (!Q.empty()) {
      tie(d, a) = Q.top(), Q.pop();
      if (vis[a]) continue;
      vis[a] = 1;
      res += d;
      for (b = 0; b < N; ++b) {
        if (vis[b]) continue;
        Q.emplace(dist(a, b), b);
      }
    }
    printf("%.2f\n", res);
  }
  return 0;
}
