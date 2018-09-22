#include <bits/stdc++.h>
using namespace std;

struct edge {
  int n, w;
  edge() {}
  edge(int n, int w) : n(n), w(w) {}
};

using ve = vector<edge>;
using v2e = vector<ve>;
using ll = long long;
using vll = vector<ll>;
using v2ll = vector<vll>;
using v3ll = vector<v2ll>;
using ti4 = tuple<ll, int, int, int>;
ll INF = 1e18;
int MAX_R = 13;
int S, R, L, B;
// U, R, D, L
int DR[] = {-1, 0, 1, 0};
int DC[] = {0, 1, 0, -1};

bool in_range(int r, int c) {
  return 0 <= r && r < MAX_R && 0 <= c && c < MAX_R;
}

bool u_turn(int da, int db) {
  return (da + 2) % 4 == db;
}

ll weight(int da, int db) {
  if ((da + 1) % 4 == db) return R;
  if ((db + 1) % 4 == da) return L;
  return S;
}

void debug(v3ll &D) {
  cout << endl;
  for (auto &row : D) {
    for (auto &cell : row) {
      cout << "[";
      for (auto n : cell) {
        if (n == INF) cout << "I ";
        else cout << n << " ";
      }
      cout << "] ";
    }
    cout << endl;
  }
  cout << endl;
}

v3ll dijkstra(int r, int c, vll &C) {
  int dir, nr, nc;
  ll w, nw;
  v3ll D(MAX_R, v2ll(MAX_R, vll(4, INF)));
  D[r][c] = C;
  priority_queue<ti4> Q;
  for (int i = 0; i < 4; ++i) {
    if (C[i] != INF) Q.emplace(-C[i], r, c, i);
  }
  while (!Q.empty()) {
    tie(w, r, c, dir) = Q.top(); Q.pop(); w *= -1;
    for (int i = 0; i < 4; ++i) {
      if (u_turn(dir, i)) continue;
      nr = r + DR[i], nc = c + DC[i];
      if (!in_range(nr, nc)) continue;
      nw = w + weight(dir, i) + B;
      if (nw < D[nr][nc][i]) {
        D[nr][nc][i] = nw;
        Q.emplace(-nw, nr, nc, i);
      }
    }
  }
  return D;
}

int main() {
  int n, r = 6, c = 6;
  cin >> B >> S >> R >> L >> n;
  v3ll D(MAX_R, v2ll(MAX_R, vll(4, 0)));
  while (n--) {
    D = dijkstra(r, c, D[r][c]);
    cin >> c >> r;
    r = 6 - r, c += 6;
  }
  ll res = INF;
  for (ll ans : D[r][c]) res = min(res, ans);
  cout << res << endl;
  return 0;
}
