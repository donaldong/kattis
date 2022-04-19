/**
 * @date        2022-04-18
 * @tags        implementation
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  vector<string> grid(7);
  for (auto& row : grid) cin >> row;
  grid[3][3] = 0;
  auto getChar = [&](int r, int c) -> char {
    if (r < 0 || r >= 7 || c < 0 || c >= 7) return 0;
    return grid[r][c];
  };
  auto dot = [&](int r, int c) -> bool { return getChar(r,c) == '.'; };
  auto W = [&](int r, int c) -> bool { return getChar(r,c) == 'W'; };
  array<int,4> DR{0,-1, 0,1};
  array<int,4> DC{1, 0,-1,0};
  auto step = [&](int r, int c, int d) -> pair<int,int> {
    if (r < 0 || r >= 7 || c < 0 || c >= 7) return {-1,-1};
    r += DR[d], c += DC[d];
    while (0 <= r && r < 7 && 0 <= c && c < 7) {
      char v = grid[r][c];
      if (v == '.' || v == 'W') return {r, c};
      switch (d) {
        case 0: case 2: {
          if (v != '-') return {-1,-1};
          break;
        }
        case 1: case 3: {
          if (v != '|') return {-1,-1};
          break;
        }
      }
      r += DR[d], c += DC[d];
    }
    return {-1,-1};
  };
  auto mill = [&](int r, int c) {
    if (!W(r,c)) return false;
    for (int d = 0; d < 4; ++d) {
      {
        auto [i2, j2] = step(r, c, d);
        auto [i3, j3] = step(i2, j2, d);
        if (W(i2,j2) && W(i3,j3)) return true;
      }
      auto [i2, j2] = step(r, c, d);
      auto [i3, j3] = step(r, c, (d+2)%4);
      if (W(i2,j2) && W(i3,j3)) return true;
    }
    return false;
  };
  auto double_mill = [&]() {
    for (int i = 0; i < 7; ++i) for (int j = 0; j < 7; ++j) {
      if (!mill(i, j)) continue;
      for (int d = 0; d < 4; ++d) {
        auto [i2, j2] = step(i, j, d);
        if (!dot(i2, j2)) continue;
        swap(grid[i2][j2], grid[i][j]);
        if (mill(i2, j2)) return true;
        swap(grid[i2][j2], grid[i][j]);
      }
    }
    return false;
  };
  cout << (double_mill() ? "double mill" : "no double mill") << endl;
  return 0;
}
