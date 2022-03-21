#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> T(n);
  for (int& t : T) cin >> t;
  int d = -1, t = INT_MAX;
  for (int i = 0; i+2< n; ++i) {
    int k = max(T[i],T[i+2]);
    if (k<t) {
      d = i+1;
      t = k;
    }
  }
  cout << d << ' ' << t << endl;
  return 0;
}
