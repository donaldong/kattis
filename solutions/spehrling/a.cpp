/**
 * @date        2022-05-09
 * @tags        dp
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  string s1, s2;
  cin >> s1 >> s2;
  int len1 = s1.size(), len2 = s2.size();
  vector<vector<int>> DP(len1+1, vector<int>(len2+1, -1));

  function<int(int,int)> dfs = [&](int p1, int p2) {
    auto &res = DP[p1][p2];
    if (res >= 0) return res;
    if (p2 == 0) return res = p1;
    if (p1 == 0) return res = p2;
    if (s1.substr(0, p1) == s2.substr(0, p2)) return res = 0;
    res = dfs(p1-1, p2-1)+2; // delete, type
    res = min(res, dfs(p1-1, p2)+1); // delete
    return res = min(res, dfs(p1, p2-1)+1); // type
  };

  cout << dfs(len1, len2) << endl;
  return 0;
}
