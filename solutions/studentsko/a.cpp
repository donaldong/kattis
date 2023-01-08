/**
 * @date        2023-01-07
 * @tags        dp, LIS
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
int lis(vector<int>& N) {
  vector<int> DP(N.size()+1, INT_MAX);
  DP[0] = -1;
  for (int v : N) {
    auto itr = upper_bound(DP.begin(), DP.end(), v);
    *itr = v;
  }
  for (int i = DP.size()-1; i >= 1; --i) {
    if (DP[i] != INT_MAX) return i;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, k;
  cin >> n >> k;
  vector<int> N(n);
  for (int& v : N) cin >> v;
  vector<int> N2(N);
  sort(N2.begin(), N2.end());
  unordered_map<int, int> T;
  for (int i = 0, j = 0; j < n; ++i) {
    for (int _ = 0; _ < k; ++_, ++j) T[N2[j]] = i;
  }
  for (auto& v : N) v = T[v]; // compress the skill number to team ID
  cout << n-lis(N) << endl; // move elements in favor of the LIS
  return 0;
}
