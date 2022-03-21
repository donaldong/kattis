#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int res = 0, w = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x > w) w = x,  ++res;
    else w = x;
  }
  cout << res << endl;
  return 0;
}
