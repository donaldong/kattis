#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>&S, int m, int k) {
  int res = k;
  for (int s : S) {
    int r = 0;
    for (int i = 0; i < k; ++i) {
      if ((s & (1<<i)) == (m & (1<<i))) ++r;
    }
    res = min(res, r);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> S(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int v = 0;
    for (int j = 0; j < k; ++j) {
      if (s[j] == 'T') v += 1;
      if (j+1 != k) v <<= 1;
    }
    S[i] = v;
  }
  int res = 0;
  for (int m = (1<<k)-1; m >= 0; --m) {
    res = max(res, solve(S, m, k));
  }
  cout << res << endl;
  return 0;
}
