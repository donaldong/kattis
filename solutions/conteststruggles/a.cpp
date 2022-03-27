/**
 * @date        2022-03-26
 * @tags        math
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N,K,D,S;
  cin >> N >> K >> D >> S;
  int tot = N*D, totSolved = K*S;
  int numUnsolved = N-K;
  double res = tot-totSolved;
  res /= numUnsolved;
  if (res < 0.0 || res > 100.0) cout << "impossible" << endl;
  else cout << setprecision(12) << res << endl;
  return 0;
}
