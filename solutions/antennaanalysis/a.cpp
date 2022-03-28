/**
 * @date        2022-03-27
 * @tags        moving window, dp, case work
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  long long C;
  cin >> N >> C;
  vector<int> X(N);
  for (int& x: X) cin >> x;
  long long add = LLONG_MIN, sub = LLONG_MIN;
  for (int i = 0; i < N; ++i) {
		// either Xj+ C*j - Xi - C*i
		// or i	 -Xj+ C*j + Xi - C*i depending on Xj<=>Xi
    long long res = 0;
    if (add != LLONG_MIN) res = max(res, add-X[i]-C*i);
    if (sub != LLONG_MIN) res = max(res, sub+X[i]-C*i);
    add = max(add, X[i]+C*i), sub = max(sub, -X[i]+C*i);
    printf("%lld ", res);
  }
  printf("\n");
  return 0;
}
