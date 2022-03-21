#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> P;
  P.reserve(n);
  for (int i = 0; i < n; ++i) {
    int t, k;
    cin >> t >> k;
    P.emplace_back(k, t);
  }
  sort(P.begin(), P.end());

  long long res = 0;
  unsigned int expected = 1;
  for (auto [k, t] : P) {
    if (t <= expected) {
      ++expected;
      continue;
    }
    res += t-expected;
    expected = t+1;
  }
  cout << res << endl;
  return 0;
}
