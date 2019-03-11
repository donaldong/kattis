#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;
int DR[] = {-1, 0, 1, 0};
int DC[] = {0, 1, 0, -1};
int REV[] = {2, 3, 0, 1};
string MSG[] = {"up", "right", "down", "left"};
int UK = -1, SPACE = 0, WALL = 1;
int MAX_DIM = 202;
v3i G(MAX_DIM, v2i(MAX_DIM, vi(4, UK)));

bool check(int r, int c, int i) {
  int nr, nc;
  nr = r + DR[i], nc = c + DC[i];
#ifdef DEBUG
  printf("%d %d => %d %d (%d)\n", r, c, nr, nc, G[r][c][i]);
#endif
  if (nr < 0 || nr >= MAX_DIM || nc < 0 || nc >= MAX_DIM)
    return false;
  return G[r][c][i] < WALL;
}

void mark(int r, int c, int i, int v)  {
#ifdef DEBUG
  printf("%d %d %s is now blocked\n", r, c, MSG[i].c_str());
#endif
  G[r][c][i] = WALL;
  int nr, nc;
  nr = r + DR[i], nc = c + DC[i];
  if (v > G[nr][nc][REV[i]]) G[nr][nc][REV[i]] = v;
}

bool dfs(int r, int c, int p) {
  string res;
  if (p != -1) p = REV[p];
  for (int i = 0; i < 4; ++i) {
    if (i == p) continue;
    if (!check(r, c, i)) continue;
    cout << MSG[i] << endl;
    cin >> res;
    if (res == "solved") return true;
    else if (res == "ok") mark(r, c, i, SPACE);
    else if (res == "wall") {
      mark(r, c, i, WALL);
      continue;
    } else exit(-1);
    if (dfs(r + DR[i], c + DC[i], i)) return true;
  }
  if (r == 101 && c == 101) {
    cout << "no way out" << endl;
    return false;
  }
  cout << MSG[p] << endl;
  cin >> res;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  dfs(101, 101, -1);
  return 0;
}
