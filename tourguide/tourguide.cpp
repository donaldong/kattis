#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using uint = unsigned int;

struct person {
  ld x, y, v, a;
  ld vx, vy;
};

// My velocity
ld V;
// people
vector<person> P;

ld dist(ld x1, ld y1, ld x2, ld y2) {
  ld dx = x1 - x2;
  ld dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

ld reach(person &p, ld x, ld y) {
  ld a = p.vx * p.vx + p.vy * p.vy - V * V;
  ld dx = p.x - x, dy = p.y - y;
  ld b = 2 * dx * p.vx;
  b += 2 * dy * p.vy;
  ld c = dx * dx + dy * dy;
  ld delta = sqrt(b* b - 4.0 * a * c);
  ld res = (-b + delta) / 2.0 / a;
  if (res > 0) return res;
  return (-b - delta) / 2.0 / a;
}

void update(person &p, ld t) {
  p.x += t * p.vx;
  p.y += t * p.vy;
}

ld time_back(person &p) {
  ld d = dist(p.x, p.y, 0, 0);
  return d / p.v;
}

ld solve(vector<int> &O) {
  ld res = 0, t = 0, x = 0, y = 0;
  for (int i : O) {
    auto p = P[i];
    update(p, t);
    ld delta = reach(p, x, y);
    update(p, delta);
    t += delta;
    res = max(res, t + time_back(p));
    x = p.x;
    y = p.y;
  }
  return res;
}

int main() {
  int N;
  while (cin >> N) {
    if (!N) break;
    cin >> V;
    P = vector<person>(N);
    for (auto &p : P) {
      cin >> p.x >> p.y >> p.v >> p.a;
      p.vx = p.v * cos(p.a);
      p.vy = p.v * sin(p.a);
    }
    ld res = 1e10;
    vector<int> order(N);
    for (int i = 0; i < N; ++i) order[i] = i;
    do {
      res = min(res, solve(order));
    } while (next_permutation(order.begin(), order.end()));
    cout << round(res) << endl;
  }
  return 0;
}
