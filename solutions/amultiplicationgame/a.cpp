#include <bits/stdc++.h>
using namespace std;
struct Solution {
  long long n;
  array<unordered_map<long long,int>, 2> dp;

  Solution(long long n) : n(n) {}

  int dfs(long long v, int p) {
    if (v >= n) return 1-p;
    if (dp[p].count(v)) return dp[p][v];
    bool couldWin = false;
    for (int i = 2; i <= 9; ++i) {
      if (dfs(v*i, 1-p) == p) couldWin = true;
    }
    return dp[p][v] = couldWin ? p : 1-p;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  while (cin >> n) {
    Solution s(n);
    printf("%s wins.\n", s.dfs(1, 0)==0 ? "Stan" : "Ollie");
  }
  return 0;
}
