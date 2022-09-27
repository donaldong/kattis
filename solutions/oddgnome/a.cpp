/**
 * @date        2022-09-23
 * @tags        implementation
 * @difficulty  900
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& v : nums) cin >> v;
    for (int i = 1; i < n; ++i) {
      if (nums[i] != nums[i-1]+1) {
        cout << i+1 << endl;
        break;
      }
    }
  }
  return 0;
}
