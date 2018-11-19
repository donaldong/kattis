#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi N(n);
  for (int i = 0; i < n; ++i) cin >> N[i];
  sort(N.rbegin(), N.rend());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(res, i + 2 + N[i]);
  }
  cout << res << endl;
  return 0;
}
