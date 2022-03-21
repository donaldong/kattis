#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int s = 0;
  vector<int> T(n), D(n);
  for (int i = 0; i < n; ++i) {
    cin >> T[i] >> D[i];
  }
  for (int i = 1; i < n; ++i) {
    int dt = T[i]-T[i-1], dd = D[i]-D[i-1];
    s = max(s, dd/dt);
  }
  cout << s << endl;
  return 0;
}
