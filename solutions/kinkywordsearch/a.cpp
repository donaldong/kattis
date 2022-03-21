#include <bits/stdc++.h>
using namespace std;
using vec1d = vector<int>;
using vec2d = vector<vec1d>;
using vec3d = vector<vec2d>;
using vec4d = vector<vec3d>;
using vec5d = vector<vec4d>;

int R,C,K;
vec2d G;
vec5d DP;
string W;
vec1d DR{0,0,  1,1,1,  -1,-1,-1};
vec1d DC{1,-1, -1,1,0, -1, 1, 0};

int dfs(int i, int r, int c, int k, int d) {
  if (k < 0) return false;
  if (r < 0 || r >= R || c < 0 || c >= C) return false;
  if (W[i] != G[r][c]) return 0;
  auto& res = DP[i][r][c][k][d];
  if (res >= 0) return res;
#ifdef DEBUG
  printf("dfs(i=%d, r=%d, c=%d, k=%d, d=%d)\n", i,r,c,k,d);
#endif
  if (i+1 == W.size()) return res = k == 0;
  res = false;
  for (int d2 = 0; d2 < 8; ++d2) {
    int r2 = r+DR[d2], c2 = c+DC[d2], k2 = (d==d2||d==8)?k:k-1;
    if (dfs(i+1, r2, c2, k2, d2)) return res = true;
  }
  return res = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  G.assign(R, vec1d(C, 0));
  for (auto& row : G) for (auto& cell : row) {
    char c;
    cin >> c;
    cell = c;
  }
  cin >> K >> W;
  if (K>=W.size()) goto fail;
  DP.assign(W.size(), vec4d(R, vec3d(C, vec2d(K+1, vec1d(9, -1)))));

  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
    if (dfs(0, r, c, K, 8)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

fail:
  cout << "No" << endl;
  return 0;
}
