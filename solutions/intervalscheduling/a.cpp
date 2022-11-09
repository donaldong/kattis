/**
 * @date        2022-10-28
 * @tags        greedy, sorting
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  using pii = pair<int,int>;
  vector<pair<int,int>> ranges(n);
  for (auto& p : ranges) cin >> p.first >> p.second;
  sort(ranges.begin(), ranges.end(), [&](const pii& a, const pii& b) {
    return a.second < b.second;
  });
  int res = 0, t = 0;
  for (const auto& p : ranges) {
    if (p.first >= t) {
      ++res;
      t = p.second;
    }
  }
  cout << res << endl;
  return 0;
}
