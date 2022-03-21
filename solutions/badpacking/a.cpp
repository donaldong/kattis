#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, C;
  cin >> n >> C;
  vector<int> W(n);
  int sum = 0;
  for (int& w : W) cin >> w, sum += w;
  if (sum <= C) {
    cout << sum << endl;
    return 0;
  }

  sort(W.begin(), W.end());
  vector<int> prefix(n);
  prefix[0] = 0;
  for (int i = 1; i < n; ++i) prefix[i] = prefix[i-1]+W[i-1];

  vector<vector<bool>> T(n, vector<bool>(C+1, false));
  for (int i = n-1; i >= 0; --i) {
    if (i+1<n) for (int j = 1; j <= C; ++j) {
      if (T[i+1][j]) T[i][j] = true;
      if (j>=W[i] && T[i+1][j-W[i]]) T[i][j] = true;
    }
    T[i][0] = T[i][W[i]] = true;
  }

  for (int waste = W.back()-1; waste >= 0; --waste) {
    auto itr = upper_bound(W.begin(), W.end(), waste);
    int i = distance(W.begin(), itr);
    int t = C-prefix[i]-waste;
#ifdef DEBUG
    printf("waste=%d i=%d C(%d)-prefix(%d)-waste(%d)=%d\n", waste, i, C, prefix[i], waste, t);
#endif
    if (t < 0) continue;
    if (T[i][t]) {
      cout << C - waste << endl;
      return 0;
    }
  }

  return 0;
}
