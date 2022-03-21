#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using uint = unsigned int;

int X, Y;

uint solve(vi &S) {
  uint res = -1;
  for (size_t i = 0; i < S.size(); ++i) {
    uint r = 0;
    for (size_t j = 0; j < S.size(); ++j) {
      if (i == j) continue;
      uint d = i > j ? i - j : j - i;
      r += d* S[j];
    }
    res = min(res, r);
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> X >> Y;
    vi Y_SUM(X, 0), X_SUM(Y, 0);
    for (int y = 0; y < Y; ++y) {
      for (int x = 0; x < X; ++x) {
        int t;
        cin >> t;
        Y_SUM[x] += t; 
        X_SUM[y] += t; 
      }
    }
    cout << solve(Y_SUM) + solve(X_SUM) << " blocks" << endl;
  }
  return 0;
}
