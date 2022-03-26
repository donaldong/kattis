/**
 * @date        2022-03-25
 * @tags        math, brute force
 * @difficulty  1200
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  long long n;
  cin >> n;
  for (int m = 2; m < n; ++m) {
    auto p = (long long)m * n;
    bool valid = true;
    for (auto i = 2LL; i * i <= p && valid; ++i) {
      if (p%(i*i)==0) valid = false;
    }
    if (valid) {
      cout << m << endl;
      return 0;
    }
  }
  return 0;
}
