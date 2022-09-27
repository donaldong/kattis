/**
 * @date        2022-09-26
 * @tags        math
 * @difficulty  1100
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int res = 0, s, n;
  cin >> s >> n;
  vector<int> N(n);
  for (auto& num : N) cin >> num;

  auto dist = [](int a, int b) -> int {
    int delta = b-a;
    if (delta < 0) return 0;
    if (delta&1) {
      return (delta+1)/2;
    }
    return delta/2+1;
  };

  res += dist(N.back()+2, s+N[0]-2);
  for (int i = 1; i < n; ++i) res += dist(N[i-1]+2, N[i]-2);
  cout << res << endl;
  return 0;
}
