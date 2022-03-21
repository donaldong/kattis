#include <bits/stdc++.h>
using namespace std;

int L, R, C;
// L, R, C
vector<vector<string>> G;

struct pt {
  int l, r, c;
  int step;
  pt() {}
  pt(int l, int r, int c, int step=0) :
    l(l), r(r), c(c), step(step) {}
};

int DL[] = {1, -1, 0, 0, 0, 0};
int DR[] = {0, 0, 1, -1, 0, 0};
int DC[] = {0, 0, 0, 0, 1, -1};

int bfs(pt &src) {
  queue<pt> Q;
  Q.push(src);
  G[src.l][src.r][src.c] = '#';
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int i = 0; i < 6; ++i) {
      int l = cur.l + DL[i];
      int r = cur.r + DR[i];
      int c = cur.c + DC[i];
      if (0 <= l && l < L &&
          0 <= r && r < R &&
          0 <= c && c < C) {
        if (G[l][r][c] == 'E') return cur.step + 1;
        if (G[l][r][c] == '.') {
          Q.emplace(l, r, c, cur.step + 1);
          G[l][r][c] = '#';
        }
      }
    }
  }
  return -1;
}

int main() {
  while (cin >> L >> R >> C) {
    if (!L && !R && !C) break;
    pt src;
    G = vector<vector<string>>(L, vector<string>(R));
    for (int l = 0; l < L; ++l) {
      for (int r = 0; r < R; ++r) {
        cin >> G[l][r];
        for (int c = 0; c < C; ++c) if (G[l][r][c] == 'S') src = pt(l, r, c);
      }
    }
    int res = bfs(src);
    if (res < 0) cout << "Trapped!" << endl;
    else cout << "Escaped in " << res << " minute(s)." << endl;
  }
  return 0;
}
