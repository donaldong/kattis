#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;

bool match(v2i &G, int val, int r, vi &P, vb &V) {
  for (size_t c = 0; c < G.size(); ++c) {
    if (G[r][c] < val || V[c]) continue;
    V[c] = true;
    if (P[c] < 0 || match(G, val, P[c], P, V)) {
      P[c] = r;
      return true;
    }
  }
  return false;
}

bool possible(v2i &G, int val) {
  vi P(G.size(), -1);
  for (size_t i = 0; i < G.size(); ++i) {
    vb V(G.size(), false);
    if (!match(G, val, i, P, V)) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  v2i G(n, vi(n));
  vi T(n * n);
  int k = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cin >> G[i][j];
    T[k++] = G[i][j];
  }
  sort(T.begin(), T.end());
  auto end = unique(T.begin(), T.end());
  int lo = 0, hi = end - T.begin() - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (possible(G, T[mid + 1])) lo = mid + 1;
    else hi = mid;
  }
  cout << T[lo] << endl;
  return 0;
}
