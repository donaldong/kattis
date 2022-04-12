/**
 * @date        2022-04-11
 * @tags        probability, math, dp
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
using vi = vector<double>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using v4i = vector<v3i>;
using v5i = vector<v4i>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int R,G,B,Y,S;
  cin >> R >> G >> B >> Y >> S;
  v5i DP(R+1,v4i(G+1,v3i(B+1, v2i(Y+1, vi(S+1, -1.0)))));
  function<double(int,int,int,int,int)> dfs = [&](int r, int g, int b, int y, int s) {
    auto& res = DP[r][g][b][y][s];
    if (res >= 0.0) return res;
    if (s >= S) return res = 0.0;
    if (r + g + b + y == 0) return res = 1.0;
    int maxCnt, f = 2, f2 = 0;
    double sum = 0.0, subsum = 0.0;
    if (r) ++f, sum += dfs(r-1,g,b,y,s);
    if (g) ++f, sum += dfs(r,g-1,b,y,s);
    if (b) ++f, sum += dfs(r,g,b-1,y,s);
    if (y) ++f, sum += dfs(r,g,b,y-1,s);
    sum += dfs(r,g,b,y,s+1), maxCnt = max({r,g,b,y});
    if (r == maxCnt) ++f2, subsum += dfs(r-1,g,b,y,s);
    if (g == maxCnt) ++f2, subsum += dfs(r,g-1,b,y,s);
    if (b == maxCnt) ++f2, subsum += dfs(r,g,b-1,y,s);
    if (y == maxCnt) ++f2, subsum += dfs(r,g,b,y-1,s);
    sum += subsum / f2;
    sum /= f;
    return res = sum;
  };
  cout << setprecision(12) << dfs(R,G,B,Y,0) << endl;
  return 0;
}
