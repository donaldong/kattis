#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> N(n);
  for (int& v : N) cin >> v;
  int res = 0;
  sort(N.begin(), N.end());
  for (int i = 0; i < n; ++i) {
    res +=  N[i];
    while (i+1< n && N[i+1]==N[i]+1) ++i;
  }
  cout << res << endl;
  return 0;
}
