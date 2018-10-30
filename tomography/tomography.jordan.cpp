#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;

bool possible(vi &R, vi &C) {
  for (int r : R) if (r) return false;
  for (int c : C) if (c) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vi R(m), C(n);
  map<int, v2i> M;
  for (int &r : R) cin >> r;
  for (int &c : C) cin >> c;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      M[R[r] * C[c]].push_back({r, c});
    }
  }
  for (auto itr = M.rbegin(); itr != M.rend(); ++itr) {
    for (auto &pairs : itr->second) {
      if (R[pairs[0]] && C[pairs[1]]) {
        --R[pairs[0]], --C[pairs[1]];
      }
    }
  }
  cout << (possible(R, C) ? "Yes" : "No") << endl;
  return 0;
}
