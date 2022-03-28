/**
 * @date        2022-03-27
 * @tags        geometry
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int K = 1001;
  vector<vector<bool>> G(K, vector<bool>(K, false)); // rasterize into a low res grid
  double scale = 1000.0 / 30.0;
  int n;
  double x, y, r;
  cin >> n;
  while (n--) {
    cin >> x >> y >> r;
    double t = (y-r+10.0)*scale, l = (x-r+10.0)*scale, w = 2.0*r*scale;
    for (int i = t; i < t+w; ++i) for (int j = l; j < l+w; ++j) {
      double x2 = j, y2 = i;
      x2 = x2/scale-10.0, y2 = y2/scale-10.0;
      double dx = x-x2, dy = y-y2;
      if (dx*dx+dy*dy<=r*r) G[i][j] = true;
    }
  }
  int cnt = 0;
  for (auto& row : G) for (auto cell : row) if (cell) ++cnt;
  cout << setprecision(12) << (double)cnt/scale/scale << endl;
  return 0;
}
