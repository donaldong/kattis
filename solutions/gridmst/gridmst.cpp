#include <bits/stdc++.h>
using namespace std;

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

using vi = vector<int>;

int find(vi &P, int n) {
  if (P[n] == -1) return n;
  return P[n] = find(P, P[n]);
}

using vpt = vector<pt>;
using ve = vector<edge>;

int dist(pt &a, pt &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return abs(dx) + abs(dy);
}

int main() {
  vi N(5e9);
  for (size_t i = 0; i < N.size(); ++i) {
    N[i] = i;
  }
  return 0;
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vpt nodes(n);
  for (int i = 0; i < n; ++i) {
    cin >> nodes[i].x >> nodes[i].y;
  } 
  ve E;
  E.reserve(n * (n - 1) / 2);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      E.emplace_back(i, j, dist(nodes[i], nodes[j]));
    }
  }
  sort(E.begin(), E.end(), [](edge &a, edge &b) {
    return a.w < b.w;
  });
  vi P(n, -1);
  int a, b;
  int res = 0;
  for (size_t i = 0; i < E.size(); ++i) {
    a = find(P, E[i].a), b = find(P, E[i].b);
    if (a != b) {
      res += E[i].w;
      P[b] = a;
    }
  }
  cout << res << endl;
  return 0;
}
