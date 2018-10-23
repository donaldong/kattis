#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;

bool has_cycle(v2i &G, int c) {
  for (size_t r = 0; r < G.size(); ++r) {
    if (G[r][c] == c + 1) return false;
  }
  return true;
}

vi step(vi &A) {
  vi res(A.size());
  for (size_t i = 0; i < A.size(); ++i) {
    res[i] = A[A[i] - 1];
  }
  return res;
}

bool possible(vi &A) {
  v2i G(A.size());
  G[0] = step(A);
  for (size_t i = 1; i < G.size(); ++i) {
    G[i] = step(G[i - 1]);
  }
  for (size_t i = 0; i < A.size(); ++i) {
    if (has_cycle(G, i)) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi A(n);
    for (int &a : A) cin >> a;
    cout << (possible(A) ? "All can eat." : "Some starve.") << endl;
  }
  return 0;
}
