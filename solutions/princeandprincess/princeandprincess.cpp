#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int lis(vi &V) {
#ifdef DEBUG
  for (int v : V) printf("%d ", v);
  printf("\n");
#endif
  vi L;
  L.reserve(V.size());
  L.push_back(V[0]);
  for (int i = 1; i < V.size(); ++i) {
    int v = V[i];
    if (v < 0) continue;
    if (v < L[0]) L[0] = v;
    else if (v > L.back()) L.push_back(v);
    else *lower_bound(L.begin(), L.end(), v) = v;
#ifdef DEBUG
    for (int l : L) printf("%d ", l);
    printf("\n");
#endif
  }
  return L.size();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T, n, p, q, v;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n >> p >> q;
    ++p, ++q;
    vi Q(q), ord(n * n + 1, -1);
    for (int i = 0; i < p; ++i) cin >> v, ord[v] = i;
    for (auto &e : Q) cin >> e, e = ord[e];
    printf("Case %d: %d\n", t, lis(Q));
  }
  return 0;
}
