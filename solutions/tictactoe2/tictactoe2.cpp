#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
vs G(3);

bool win(char p) {
  string tar = string(3, p);
  for (int i = 0; i < 3; ++i) {
    if (G[i] == tar) return true;
  }
  for (int j = 0; j < 3; ++j) {
    if (string({G[0][j], G[1][j], G[2][j]}) == tar) return true;
  }
  return string({G[0][0], G[1][1], G[2][2]}) == tar ||
         string({G[0][2], G[1][1], G[2][0]}) == tar;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int O = 0, X = 0;
    for (auto &row : G) {
      cin >> row;
      for (char c : row) {
        if (c == 'O') ++O;
        else if (c == 'X') ++X;
      }
    }
    bool f = true, x = win('X'), o = win('O');
    if (O > X || O < X - 1) f = false;
    else if (x && o) f = false;
    else if (x && O >= X) f = false;
    else if (o && O != X) f = false;
    printf("%s\n", f ? "yes" : "no");
  }
  return 0;
}
