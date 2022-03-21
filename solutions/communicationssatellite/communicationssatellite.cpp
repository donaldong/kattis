#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y, r;
  bool f = false;
  point() {}
  point(int x, int y, int r) : x(x), y(y), r(r) {}
};

struct edge {
  int b;
  double w;
  edge() {}
  edge(int b, double w) : b(b), w(w) {}
  bool operator<(const edge &e) const {
    return w > e.w;
  }
};

using vp = vector<point>;

double dist(point &a, point &b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

double cost(point &a, point &b) {
  return dist(a, b) - a.r - b.r;
}

int main() {
  ios::sync_with_stdio(0);
  int N;
  scanf("%d", &N);
  vp P(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d %d", &P[i].x, &P[i].y, &P[i].r);
  }
  int k = 0;
  double res = 0.0;
  priority_queue<edge> Q;
  P[0].f = true;
  for (int i = 1; i < N; ++i) Q.emplace(i, cost(P[0], P[i]));
  while (!Q.empty()) {
    edge e = Q.top();
    Q.pop();
    if (P[e.b].f) continue;
    P[e.b].f = true;
    k += 1;
    res += e.w;
    if (k == N - 1) break;
    for (int i = 1; i < N; ++i) {
      if (P[i].f) continue;
      Q.emplace(i, cost(P[e.b], P[i]));
    }
  }
  printf("%.7f\n", res);
  return 0;
}
