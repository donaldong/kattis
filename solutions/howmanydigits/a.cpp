/**
 * @date        2022-09-30
 * @tags        math, number theory
 * @difficulty  1350
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int MAX_N = 1e6;
  vector<int> digits(MAX_N+1, 1);
  double sum_logs = 0.0;
  for (int i = 2; i <= MAX_N; ++i) {
    sum_logs += log10(i);
    digits[i] = ceil(sum_logs);
  }
  int n;
  while (cin >> n) {
    cout << digits[n] << endl;
  }
  return 0;
}
