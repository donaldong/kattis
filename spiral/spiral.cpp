#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using ll = long long;
using vi = vector<int>;
using v2i = vector<vi>;
using ti2 = tuple<int, int>;
using ti3 = tuple<int, int, int>;

int MAX_R = 1001;
int MAX_P = MAX_R * MAX_R + 1;

vb P(MAX_P, true);
v2i G(MAX_R, vi(MAX_R));
vector<ti2> CORD(MAX_P);

bool in_grid(int r, int c) {
  return 0 <= r && r < MAX_R && 0 <= c && c < MAX_R;
}

bool update(int r, int c, int v) {
  if (!in_grid(r, c) || v >= MAX_P) return false;
  G[r][c] = v;
  CORD[v] = make_tuple(r, c);
  return true;
}

// u l d r
int DR[] = {-1, 0, 1, 0};
int DC[] = {0, -1, 0, 1};

int solve(int x, int y) {
  if (x == y) return 0;
  vb M(MAX_P, false);
  auto a = CORD[x];
  queue<ti3> Q;
  Q.emplace(get<0>(a), get<1>(a), 0);
  M[x] = true;
  int r, c, step;
  while (!Q.empty()) {
    tie(r, c, step) = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      int r2 = r + DR[i];
      int c2 = c + DC[i];
      if (!in_grid(r2, c2)) continue;
      int n = G[r2][c2];
      if (P[n] || M[n]) continue;
      if (n == y) return step + 1;
      Q.emplace(r2, c2, step + 1);
      M[n] = true;
    }
  }
  return -1;
}

void build() {
  int r = 500, c = 500, v = 1;
  int step = 2;
  update(r, c, v);
  while (true) {
    ++c, ++v;
    if (!update(r, c, v)) return; 
    for (int i = 0; i < 4; ++i) {
      int k = step;
      if (!i) --k;
      for (int j = 0; j < k; ++j) {
        r += DR[i];
        c += DC[i];
        ++v;
        if (!update(r, c, v)) return; 
      }
    }
    step += 2;
  }
}

int main() {
  P[0] = P[1] = false;
  ll i = 2, j;
  for (; (j = i * i) < MAX_P; ++i) {
    if (!P[i]) continue;
    for (; j * j < MAX_P; j += i) P[j] = false;
  }
  build();
  int x, y, t = 1;
  while (cin >> x >> y) {
    int res = solve(x, y);
    printf("Case #%d: ", t++);
    if (res >= 0) cout << res << endl;
    else cout << "impossible" << endl;
  }
  return 0;
}
