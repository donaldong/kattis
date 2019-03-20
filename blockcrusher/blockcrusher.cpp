#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;

int DR[] = {0, 0, -1, -1, -1, 1, 1, 1};
int DC[] = {-1, 1, -1, 0, 1, -1, 0, 1};

void solve(vs &G, int r, int c) {
  int d1, d2, r1, c1, r2, c2;
  v2i D(r, vi(c, INT_MAX));
  v3i P(r, v2i(c));
  priority_queue<tuple<int, int, int>> Q;
  for (int i = 0; i < c; ++i) {
    d1 = G[0][i] - '0', D[0][i] = d1;
    Q.emplace(-d1, 0, i);
  }
  int min_dist = INT_MAX, r3 = r - 1, c3;
  while (!Q.empty()) {
    tie(d1, r1, c1) = Q.top(), Q.pop(), d1 *= -1;
    if (r1 + 1 == r && d1 < min_dist) {
      min_dist = d1, c3 = c1;
    }
    for (int i = 0; i < 8; ++i) {
      r2 = r1 +DR[i], c2 = c1 + DC[i];
      if (r2 < 0 || r2 >= r || c2 < 0 || c2 >= c) continue;
      d2 = d1 + G[r2][c2] - '0';
      if (d2 < D[r2][c2]) {
#ifdef DEBUG
        printf("%d %d => %d %d\n", r1, c1, r2, c2);
#endif
        D[r2][c2] = d2;
        P[r2][c2] = {r1, c1};
        Q.emplace(-d2, r2, c2);
      }
    }
  }
  for (; r3 >= 0;) {
#ifdef DEBUG
    printf("%d %d\n", r3, c3);
#endif
    G[r3][c3] = ' ';
    if (!r3) break;
    r2 = P[r3][c3][0], c2 = P[r3][c3][1];
#ifdef DEBUG
    printf(" <- %d %d\n", r2, c2);
#endif
    r3 = r2, c3 = c2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, c;
  while (cin >> r >> c) {
    if (!r && !c) break;
    vs G(r);
    for (auto &row : G) cin >> row;
    solve(G, r, c);
    for (auto &row : G) printf("%s\n", row.c_str());
    printf("\n");
  }
  return 0;
}
