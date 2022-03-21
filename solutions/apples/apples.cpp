#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> G;

string build(char c, int n) {
  string res;
  for (int i = 0; i < n; ++i) res += c;
  return res;
}

void solve() {
  vector<string> G_(C);
  // transpose
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      G_[j] += G[i][j];
    }
  }
  // fix each row
  for (int i = 0; i < C; ++i) {
    int space = 0, apple = 0;
    string row;
    for (int j = 0; j < R; ++j) {
      char c = G_[i][j];
      if (c == '.') ++space;
      else if (c == 'a') ++apple;
      else {
        row += build('.', space);
        row += build('a', apple);
        row += '#';
        apple = 0;
        space = 0;
      } 
    }
    row += build('.', space);
    row += build('a', apple);
    G_[i] = row;
  }
  // transpose
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      G[i][j] = G_[j][i];
    }
  }
}

int main() {
  cin >> R >> C;
  G = vector<string>(R);
  for (auto &row : G) cin >> row;
  solve();
  for (auto &row : G) cout << row << endl;
  return 0;
}
