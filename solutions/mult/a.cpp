#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int v0 = -1, v;
  while (n--) {
    if (v0<0) cin >> v0;
    else {
      cin >> v;
      if (v%v0==0) {
        cout << v << endl;
        v0 = -1;
      }
    }
  }
  return 0;
}
