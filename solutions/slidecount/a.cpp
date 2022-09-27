/**
 * @date        2022-09-26
 * @tags        prefix sum, sliding window, implementation
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, c;
  cin >> n >> c;
  vector<int> W(n), ps(n+1, 0);
  for (auto& w : W) cin >> w;

  int s = 0, e = -1;
  long long sum = 0;

  auto incr_s = [&]() {
    sum -= W[s];
    ++s;
  };
  auto incr_e = [&]() {
    sum += W[++e];
  };

  incr_e();
  while (s < n) {
    if (s <= e) ++ps[s], --ps[e+1];
    if (e+1 >= n) incr_s();
    else if (sum + W[e+1] > c) incr_s();
    else incr_e();
  }

  for (int i = 1; i < n; ++i) ps[i] += ps[i-1];
  for (int i = 0; i < n; ++i) printf("%d\n", ps[i]);
  return 0;
}
