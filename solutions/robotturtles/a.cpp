/**
 * @date        2022-04-11
 * @tags        grid, shortest path
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int W = 8;
  vector<string> G(W);
  for (auto& row : G) cin >> row;
  vector<vector<string>> dist(W, vector<string>(W));
  queue<tuple<int,int,int>> q;
  q.emplace(W-1,0,1);
  array<int,4> DR{-1,  0,  1,  0};
  array<int,4> DC{ 0,  1,  0, -1};
  vector<string> DDIR{"", "R", "RR", "L"};
  string res;
  while (!q.empty()) {
    auto [r,c,d] = q.front(); q.pop();
    string curr = dist[r][c];
    for (int i = 0, d2 = d; i < 4; ++i, d2=(d2+1)%4) {
      int r2 = r+DR[d2], c2 = c+DC[d2];
      if (r2 >= 0 && r2 < W && c2 >= 0 && c2 < W &&
          G[r2][c2] != 'C' && G[r2][c2] != 'T') {
        auto curr2 = curr + DDIR[i];
        if (G[r2][c2] == 'I') curr2 += 'X';
        curr2 += 'F';
        if (dist[r2][c2].empty() || dist[r2][c2].size() > curr2.size()) {
          dist[r2][c2] = move(curr2);
          q.emplace(r2, c2, d2);
          if (G[r2][c2] == 'D') {
            if (res.empty()) res = dist[r2][c2];
            else res = min(res, dist[r2][c2]);
          }
          continue;
        }
      }
    }
  }
  printf("%s\n", res.empty() ? "no solution" : res.c_str());
  return 0;
}
