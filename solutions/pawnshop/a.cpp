/**
 * @date        2022-09-26
 * @tags        greedy, data structure
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (auto& v : A) cin >> v;
  for (auto& v : B) cin >> v;

  unordered_map<int, int> nums;
  int non_zeros = 0;
  for (int i = 0; i < n; ++i) {
    int a = ++nums[A[i]];
    int b = --nums[B[i]];

    if (A[i] != B[i]) {
      if (a == 1) ++non_zeros;
      else if (a == 0) --non_zeros;
      if (b == -1) ++non_zeros;
      else if (b == 0) --non_zeros;
    }

    cout << B[i] << ' ';
    if (non_zeros == 0 && i+1 != n) cout << "# ";
  }
  cout << endl;
  return 0;
}
