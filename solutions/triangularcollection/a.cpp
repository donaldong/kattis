#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> N(n);
  for (int& v : N) cin >> v;
  sort(N.begin(), N.end());
  long long res = 0;
  for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) {
    int r = N[i]+N[j];
    long long cnt = 0;
    for (int k = j+1; k < n && r>N[k]; ++k) {
      cnt = 2*cnt + 1;
    }
    res += cnt;
  }
  cout << res << endl;
  return 0;
}
