#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int res = 1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i]!=b[i]) res<<=1;
  }
  cout << res << endl;
  return 0;
}
