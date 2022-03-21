#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> T(n);
  for (int& t : T) cin >> t;

  if (n%2) cout << "still running" << endl;
  else {
    long long res = 0;
    for (int i = 1; i < n; i += 2) {
      res += T[i]-T[i-1];
    }
    cout << res << endl;
  }

  return 0;
}
