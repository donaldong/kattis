#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> tup;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N, S, P, a, b, d, dx, dy;
  cin >> N;
  while (N--) {
    cin >> S >> P;
    vi X(P), Y(P), vis(P, 0);
    for (int i = 0; i < P; ++i) cin >> X[i] >> Y[i];
    multiset<int> res;
    priority_queue<tup, vector<tup>, greater<tup>> Q;
    Q.emplace(0, 0);
    while (!Q.empty()) {
      tie(d, a) = Q.top(), Q.pop();
      if (vis[a]) continue;
      vis[a] = 1, res.insert(d);
      for (b = 0; b < P; ++b) {
        if (vis[b]) continue;
        dx = X[a] - X[b], dy = Y[a] - Y[b];
        Q.emplace(dx * dx + dy * dy, b);
      }
    }
    --S;
    while (!res.empty() && S) {
      res.erase(--res.end()), --S;
    }
    if (res.empty()) printf("0.00\n");
    else printf("%.2lf\n", sqrt(*--res.end()));
  }
  return 0;
}
