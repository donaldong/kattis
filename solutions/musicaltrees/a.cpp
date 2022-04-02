/**
 * @date        2022-04-01
 * @tags        implementation
 * @difficulty  1350
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,m;
  cin >> n >> m;
  vector<int> P(n), T(m), C(m, 0);
  for(auto& p : P) cin >> p;
  for(auto& t : T) cin >> t;
  sort(P.begin(), P.end());
  sort(T.begin(), T.end());
  for (int i = 0; i < n; ++i) {
    int minD  = INT_MAX, t;
    for (int j = 0; j < m; ++j) {
      int d = abs(T[j]-P[i]);
      if (d < minD) minD = d, t = j;
    }
    ++C[t];
  }
  for (int c : C) n -= min(c, 1);
  cout << n << endl;
  return 0;
}
