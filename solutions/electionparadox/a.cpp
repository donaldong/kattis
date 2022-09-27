/**
 * @date        2022-09-26
 * @tags        greedy
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> votes(n);
  for (auto& p : votes) cin >> p;

  sort(votes.begin(), votes.end());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (i > n/2) {
      res += votes[i];
    } else {
      res += votes[i]/2;
    }
  }
  cout << res << endl;
  return 0;
}
