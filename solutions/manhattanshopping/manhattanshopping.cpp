#include <bits/stdc++.h>
using namespace std;

struct pt;
struct edge;
using vi = vector<int>;
using vpt = vector<pt>;
using v2pt = vector<vpt>;
using ve = vector<edge>;

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
};

struct edge {
  int a, b, w;
  edge() {}
  edge(int a, int b, int w) : a(a), b(b), w(w) {}
};

v2pt M;
ve E;

int find(vi &P, int n) {
  if (P[n] == -1) return n;
  return P[n] = find(P, P[n]);
}

bool possible(pt &a, pt &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return abs(dx) >= abs(dy);
}

bool has_horizontal_move(int i, int j) {
  for (auto &a : M[i]) for (auto &b : M[j]) {
    if (possible(a, b)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x, y, t;
  cin >> n >> m;
  M.resize(m + 1);
  E.reserve(m * (m + 1) / 2);
  M[0] = {pt(0, 0)};
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> t;
    M[t].emplace_back(x, y);
  }
  for (int i = 0; i <= m; ++i) {
    for (int j = i + 1; j <= m; ++j) {
#ifdef DEBUG
      printf(
        "has_horizontal_move from %d to %d: %d\n", 
        i, j, has_horizontal_move(i, j)
      );
#endif
      if (has_horizontal_move(i, j)) E.emplace_back(i, j, 0);
      else E.emplace_back(i, j, 1);
    }
  }
  // MST
  sort(E.begin(), E.end(), [](edge &a, edge &b) {
    return a.w < b.w;
  });
#ifdef DEBUG
  for (auto &e : E) printf("edge %d => %d: %d\n", e.a, e.b, e.w);
#endif
  vi P(m + 2, -1);
  int a, b, res = 0;
  for (auto &e : E) {
    a = find(P, e.a), b = find(P, e.b);
    if (a != b) P[b] = a, res += e.w;
  }
  cout << res << endl;
  return 0;
}
