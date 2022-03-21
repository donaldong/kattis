#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int k = m/n, r = m%n;
  for (int i = 0; i < n; ++i) {
    if (r) {
      cout << string(k+1,'*') << endl;
      --r;
    }
    else cout << string(k, '*') << endl;
  }
  return 0;
}
