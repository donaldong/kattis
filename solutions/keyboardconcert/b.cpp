/**
 * @date        2023-01-29
 * @tags        dp
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,m;
  cin >> n >> m;
  vector<vector<bool>> K(n, vector<bool>(1001, false));;
  for (int i = 0, k, j; i < n; ++i) {
    cin >> k;
    while (k--) {
      cin >> j;
      K[i][j] = true;
    }
  }
  int min_val = 0, note, inf=1e6;
  vector<int> DP(n, 0);
  while (m--) {
    int val = min_val+1;
    vector<int> DP2(n, val); // switch to min_val
    cin >> note;
    for (int i = 0; i < n; ++i) {
      auto& res = DP2[i];
      if (K[i][note]) res = min(res, DP[i]);
      else res = inf;
      val = min(val, res);
    }
    swap(val, min_val), swap(DP, DP2);
  }
  cout << min_val << endl;
  return 0;
}
