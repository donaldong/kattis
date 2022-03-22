/**
 * @author      Donald Dong
 * @date        2022-03-21
 * @tags        greedy, sorting
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int,int>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0); // Fast IO
  int N;
  cin >> N;
  vector<Pair> P(N);
  for (auto& p : P) cin >> p.first >> p.second;
  sort(P.begin(), P.end(), [](const Pair& a, const Pair& b) {
    return a.second<b.second;
  });
  int t = 0, res = 0;
  for (auto& p : P) {
    if (p.first >= t) {
      ++res;
      t = p.second;
    }
  }
  cout << res << endl;
}
