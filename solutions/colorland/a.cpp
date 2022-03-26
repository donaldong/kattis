/**
 * @date        2022-03-24
 * @tags        graph, dp
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector<int> DP(N, INT_MAX);
  unordered_map<string,int> pos;
  vector<string> C(N);
  for (auto& col : C) cin >> col;

  pos[C.back()]=N-1, DP.back() = 0;
  for (int i = N-2; i >= 0; --i) {
    auto& d = DP[i];
    for (auto& [c, j] : pos) {
      d = min(d, DP[j]+1);
    }
    pos[C[i]] = i;
  }
  int res = INT_MAX;
  for (auto& [c, j] : pos) {
    if (DP[j] != INT_MAX) res = min(res, DP[j]+1);
  }
  cout << res << endl;
  return 0;
}
