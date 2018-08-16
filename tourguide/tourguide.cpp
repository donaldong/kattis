#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using uint = unsigned int;

struct person {
  ld x, y, v, a;
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
  auto v2 = complex<ld>(p.x - x, p.y - y);
  ld alpha = M_PI - abs(p.a - arg(v2));
  ld a = p.v * p.v - V * V; 
  ld d = dist(p.x, p.y, x, y);
  ld b = -2.0 * cos(alpha) * d * p.v;
  ld c = d * d;
  ld delta = sqrt(b * b - 4.0 * a * c);
  return (-b - delta) / 2.0 / a;
}

void update(person &p, ld t) {
  complex<ld> c = polar(t * p.v, p.a);
  p.x += c.real();
  p.y += c.imag();
}

ld time_back(person &p) {
  ld d = dist(p.x, p.y, 0, 0);
  return d / p.v;
}

uint solve(vector<int> &O) {
  ld res = 0, t = 0, x = 0, y = 0;
  auto P_ = P;
  for (int i : O) {
    ld delta = reach(P_[i], x, y);
    for (auto &p : P_) update(p, delta);
    t += delta;
    res = max(res, t + time_back(P_[i]));
    x = P_[i].x;
    y = P_[i].y;
  }
  return round(res);
}

int main() {
  int N;
  while (cin >> N) {
    if (!N) break;
    cin >> V;
    P = vector<person>(N);
    for (auto &p : P) cin >> p.x >> p.y >> p.v >> p.a;
    uint res = -1;
    vector<int> order(N);
    for (int i = 0; i < N; ++i) order[i] = i;
    do {
      res = min(res, solve(order));
    } while (next_permutation(order.begin(), order.end()));
    cout << res << endl;
  }
  return 0;
}
