#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b, w;
  edge() {}
  edge(int a, int b, int w) : a(a), b(b), w(w) {}
};

using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, f, n, a, b, w;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> f >> n;
    vb F(n);
    while (f--) {
      cin >> a;
      --a;
      F[a] = true;
    }
    cin.ignore();
    v2i G(n, vi(n, INF));
    string line;
    while (true) {
      getline(cin, line);
      if (line.empty()) break;
      stringstream ss(line);
      ss >> a >> b >> w;
      --a, --b;
      G[a][b] = w;
      G[b][a] = w;
    }
    floyd(G);
    if (i) printf("\n");
    printf("%d\n", solve(G, F));
  }
  return 0;
}
