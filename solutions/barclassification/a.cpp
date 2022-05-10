/**
 * @date        2022-05-09
 * @tags        brute force
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N, ones = 0;
  cin >> N;
  vector<string> G(N);
  for (auto& row : G) {
    cin >> row;
    for (char c : row) if (c == '1') ++ones;
  }

  auto possible = [&](int c) {
    int ops = 0;
    for (int r = 0; r < N; ++r) {
      if (G[r][c] != '1') ++ops;
    }
    return ones-(N-ops)+ops <= N;
  };

  auto rotate = [&]() {
    vector<string> G2(N, string(N, 'X'));
    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
      G2[c][N-r-1] = G[r][c];
    }
    swap(G, G2);
  };

  bool v = false, h = false;
  for (int i = 0; i < N && !v; ++i) if (possible(i)) v = true;
  rotate();
  for (int i = 0; i < N && !h; ++i) if (possible(i)) h = true;
  if ((v && h) || (!v && !h)) cout << '+';
  else {
    if (v) cout << '|';
    else cout << '-';
  }
  cout << endl;
  return 0;
}
