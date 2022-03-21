#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using hset = unordered_set<int>;
using que = queue<tuple<int, int>>;

int R;
v2i G;
hset K;

bool has(int i) {
  return K.find(i) != K.end();
}

int first_non_zero(int r, int &c) {
  for (size_t i = 0; i < G[r].size(); ++i) {
    if (G[r][i] != 0) {
      c = i;
      return G[r][i];
    }
  }
  return 0;
}

int last_non_zero(int r, int &c) {
  for (size_t i = G[r].size(); i-- > 0;) {
    if (G[r][i] != 0) {
      c = i;
      return G[r][i];
    }
  }
  return 0;
}

int add_all(que &Q, int r, int c1, int c2) {
  int res = 0;
  for (int i = c1 + 2; i < c2; i += 2) {
    if (has(G[r][i])) res += 2;
    else Q.emplace(r, i), G[r][i] = 0;
  }
  return res;
}

int DR[] = {-1, -1, 0, 1, 1, 0};
int DC[] = {-1, 1, 2, 1, -1, -2};

int solve() {
  int r, r2, c1, c2, i, res = 0, k = 0;
  que Q;
  // first row
  r = 0;
  i = first_non_zero(r, c1);
  if (has(i)) res += 3;
  else Q.emplace(r, c1), G[r][c1] = 0;
  i = last_non_zero(r, c2);
  if (has(i)) res += 3;
  else Q.emplace(r, c2), G[r][c2] = 0;
  res += add_all(Q, r, c1, c2);

  for (r = 1; r + 1 < G.size(); ++r) {
    i = first_non_zero(r, c1);
    if (has(i)) res += r + 1 == R ? 3 : 2;
    else Q.emplace(r, c1), G[r][c1] = 0;
    i = last_non_zero(r, c1);
    if (has(i)) res += r + 1 == R ? 3 : 2;
    else Q.emplace(r, c1), G[r][c1] = 0;
  }

  // last row
  r = G.size() - 1;
  i = first_non_zero(r, c1);
  if (has(i)) res += 3;
  else Q.emplace(r, c1), G[r][c1] = 0;
  i = last_non_zero(r, c2);
  if (has(i)) res += 3;
  else Q.emplace(r, c2), G[r][c2] = 0;
  res += add_all(Q, r, c1, c2);

  // bfs
  while (!Q.empty()) {
    tie(r, c1) = Q.front(), Q.pop();
    for (k = 0; k < 6; ++k) {
      r2 = r + DR[k], c2 = c1 + DC[k];
      if (r2 < 0 || r2 >= G.size()) continue;
      if (c2 < 0 || c2 >= G[r2].size()) continue;
      if (!G[r2][c2]) continue;
      if (has(G[r2][c2])) {
#ifdef DEBUG
        printf("%d %d => %d %d\n", r, c1, r2, c2);
#endif
        ++res; continue;
      }
      Q.emplace(r2, c2), G[r2][c2] = 0;
    }
  }

#ifdef DEBUG
  for (int i = 0; i < G.size(); ++i) {
    for (int j = 0; j < G[i].size(); ++j) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
#endif
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r, k, n, m, i, j, p, lvl, cnt, cur;
  cin >> r >> k;
  R = r;

  while (k--) {
    cin >> i;
    K.insert(i);
  }

  n = 2 * r - 1, m = 2 * n - 1;
  G.assign(n, vi(m, 0));

  // first half
  cur = p = (r + n) * r / 2;
  for (lvl = 0; lvl < r; ++lvl) {
    j = m - 1 - lvl;
    cnt = n - lvl;
    while (cnt--) {
      G[r - 1 - lvl][j] = cur--;
      j -= 2;
    }
  }

  // second half
  cur = p;
  for (lvl = 1; lvl < r; ++lvl) {
    j = lvl;
    cnt = n - lvl;
    while (cnt--) {
      G[r - 1 + lvl][j] = ++cur;
      j += 2;
    }
  }

#ifdef DEBUG
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
#endif

  printf("%d\n", solve());
  return 0;
}
