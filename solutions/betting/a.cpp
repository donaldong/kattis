/**
 * @date        2022-09-26
 * @tags        math
 * @difficulty  900
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  double a;
  cin >> a;
  cout << setprecision(5) << 1.0+(100-a)/a << endl << 1.0+a/(100-a) << endl;
  return 0;
}
