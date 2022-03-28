/**
 * @date        2022-03-27
 * @tags        math
 * @difficulty  1150
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int k, res = INT_MAX;
  cin >> k;
  while (k--) {
    int y, c1, c2;
    cin >> y >> c1 >> c2;
    res = min(res, y+lcm(c1, c2));
  }
  cout << res << endl;
  return 0;
}
