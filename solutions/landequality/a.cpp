#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int R, C;
  cin >> R >> C;
  vector<vector<int>> G(R, vector<int>(C));
  array<int,3> freq{0};
  for (auto& row : G) for (auto& cell : row) cin >> cell, ++freq[cell];
  auto diff1 = [&]() -> bool {
    if (R>=2 && C>=2) return true;
    return G[0][0] == 1 || G[R-1][C-1] == 1;
  };
  auto solve = [&]() -> long long {
    if (freq[0]>=2) return 0;
    if (freq[0]==0) { // 0:0, 1:x, 2:x
      if (freq[2]==0) { // 0:0, 1:x, 2:0
        return freq[1]%2;
      }
      if (freq[2]%2) {
        long long a = 1, b = 1;
        int k = freq[2]/2;
        a <<= k+1, b <<= k;
        return a-b;
      } else return 0;
    }
    if (freq[1]==0) return 2; // 0:1, 1:0, 2:x
    if (freq[2]==0) return 1; // 0:1, 1:x, 2:0
    return diff1() ? 1 : 2;  // 0:1, 1:x, 2:x
  };
  cout << solve() << endl;
  return 0;
}
