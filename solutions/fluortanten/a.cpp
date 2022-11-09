/**
 * @date        2022-10-07
 * @tags        prefix sum
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> nums(n-1);
  for (auto& num : nums) {
    cin >> num;
    if (!num) cin >> num;
  }

  using ll = long long;
  ll res = LLONG_MIN;
  vector<ll> L(n+2, 0), R(n+2, 0);

  for (int i = 0; i < nums.size(); ++i) {
    L[i+1] = L[i]+nums[i]*(i+1);
  }
  for (int i = n; i >= 2; --i) {
    R[i] = R[i+1]+nums[i-2]*i;
  }
  for (int i = 1; i <= n; ++i) {
    res = max(res,  L[i-1] + R[i+1]);
  }
  cout << res << endl;
  return 0;
}
