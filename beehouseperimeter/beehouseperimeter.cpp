#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;
int DR[] = {-1, -1, 0, 1, 1, 0};
int DC[] = {-1, 0, 1, 1, 0, -1};

void debug(v2i &G) {
  for (auto &row : G) {
    for (auto &cell : row) cout << cell << " ";
    cout << endl;
  }
  cout << endl;
}

void debug(vb &H) {
  for (auto h : H) cout << h << " ";
  cout << endl;
}

v2i build(int k, int &cur) {
  v2i G(2 * k - 1, vi(2 * k - 1, -1));
  int r = 3;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < r; ++j) {
      G[i][j] = cur++;
    }
    ++r;
  }
  --r;
  int c = 0;
  for (size_t i = k; i < G.size(); ++i) {
    for (int j = ++c; j < r; ++j) {
      G[i][j] = cur++;
    }
  }
  return G;
}

bool in_range(v2i &G, int r, int c) {
  return 0 <= r && r < G.size() && 0 <= c && c < G.back().size();
}

bool out_of_bound(v2i &G, int r, int c) {
  if (!in_range(G, r, c)) return true;
  return G[r][c] == -1;
}

vi bfs(v2i &G, vb &H, vb &M, int r, int c) {
  queue<tuple<int, int>> Q;
  int nr, nc, cur;
  cur = G[r][c];
  vi res = {cur};
  Q.emplace(r, c);
  M[cur] = true;
  bool oob = false;
  while (!Q.empty()) {
    tie(r, c) = Q.front(); Q.pop();
    for (int i = 0; i < 6; ++i) {
      nr = r + DR[i];
      nc = c + DC[i];
      if (out_of_bound(G, nr, nc)) {
        oob = true;
        continue;
      }
      cur = G[nr][nc];
      if (H[cur] || M[cur]) continue;
      Q.emplace(nr, nc);
      M[cur] = true;
      if (!oob) res.push_back(cur);
    }
  }
  if (oob) return {};
  return res;
}

int solve(int k, vi &houses) {
  int size = 0, r, c, nr, nc, cur;
  auto G = build(k, size);
  vb H(size, false), V(size, false), M(size, false);
  for (auto &h : houses) H[h] = true;
  for (r = 0; r < G.size(); ++r) {
    for (c = 0; c < G[r].size(); ++c) {
      cur = G[r][c];
      if (cur == -1) continue;
      if (H[cur] || M[cur]) continue;
      auto new_houses = bfs(G, H, M, r, c);
      for (auto h : new_houses) H[h] = true;
    }
  }
  int res = 0, nxt;
  for (r = 0; r < G.size(); ++r) {
    for (c = 0; c < G[r].size(); ++c) {
      cur = G[r][c];
      if (cur == -1) continue;
      if (!H[cur]) continue;
      cout << cur + 1 << " ";
      for (int i = 0; i < 6; ++i) {
        nr = r + DR[i];
        nc = c + DC[i];
        if (out_of_bound(G, nr, nc)) {
          ++res;
          continue;
        }
        nxt = G[nr][nc];
        if (!H[nxt]) ++res;
      }
      cout << res << endl;
    }
  }
  return res;
}

int main() {
  int r, k, n;
  cin >> r >> k;
  vi H(k);
  for (auto &h : H) {
    cin >> h;
    --h;
  }
  cout << solve(r, H) << endl;
  return 0;
}
