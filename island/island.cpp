#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
int R, C, DR[4] = {-1, 1, 0, 0}, DC[4] = {0, 0, -1, 1};

void dfs(vs &G, int r, int c, char s, char t, bool skip_b, bool on_bridge) {
  if (skip_b && G[r][c] != s) G[r][c] = 'M';
  else G[r][c] = t;
  for (int i = 0; i < 4; ++i) {
    int r1 = r + DR[i], c1 = c + DC[i];
    if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C) continue;
    if (G[r1][c1] == s) dfs(G, r1, c1, s, t, skip_b, 1);
    else if (skip_b && G[r1][c1] == 'X') dfs(G, r1, c1, s, t, skip_b, 0);
    else if (skip_b && !on_bridge && G[r1][c1] == '#') dfs(G, r1, c1, s, t, skip_b, 0);
  }
}

int fill(vs &G, char s, char t, bool skip_b=0) {
  int res = 0;
  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
    if (G[r][c] == s) dfs(G, r, c, s, t, skip_b, 1), ++res;
  }
  return res;
}

int main() {
  int T = 1;
  string line;
  while (getline(cin, line)) {
    vs G;
    G.push_back(line);
    C = line.size();
    while (getline(cin, line)) {
      if (line.empty()) break;
      G.push_back(line);
    }
    R = G.size();
    printf("Map %d\n", T++);
    int buses = fill(G, 'B', 'b', true) + fill(G, '#', 'M');
    int islands = fill(G, 'M', '.'), bridges = fill(G, 'b', '.');
    printf("islands: %d\nbridges: %d\nbuses needed: %d\n\n", islands, bridges, buses);
  }
  return 0;
}
