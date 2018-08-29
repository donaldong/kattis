#include <bits/stdc++.h>
using namespace std;

struct pt;

using ld = long double;
using vld = vector<ld>;
using vpt = vector<pt>;

ld DELTA = 1e-8;

struct pt {
  ld x, y;
  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}
  bool operator<(const pt& p) {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  bool operator==(const pt & p) {
    return abs(x - p.x) < DELTA && abs(y - p.y) < DELTA;
  }
  pt operator-(const pt &p) {
    return pt(x - p.x, y - p.y);
  }
};

void update(vpt &P, int i, ld x, ld y, ld w, ld h, ld v) {
  w /= 2;
  h /= 2;
  v = v / 90.0 * M_PI_2 + M_PI_2;
  ld d_2 = sqrt(w * w + h * h);
  ld d = M_PI_2 - atan2(h, w);
  ld alpha = v - d, beta = v + d;
  pt a(cos(alpha) * d_2, sin(alpha) * d_2);
  pt b(cos(beta) * d_2, sin(beta) * d_2);
  P[4 * i] = pt(x + a.x, y + a.y);
  P[4 * i + 1] = pt(x - a.x, y - a.y);
  P[4 * i + 2] = pt(x + b.x, y + b.y);
  P[4 * i + 3] = pt(x - b.x, y - b.y);
}

ld cross(pt &a, pt &b) {
  return a.x * b.y - a.y * b.x;
}

bool cw(vpt &H, size_t n, pt &c) {
  if (H.size() < n) return true;
  size_t k = H.size() - 1;
  pt a = H[k - 1], b = H[k];
  pt ab = b - a, ac = c - a;
  return cross(ac, ab) > 0;
}

vpt convex_hull(vpt &P) {
  if (P.size() <= 1) return P;
  vpt H;
  H.reserve(P.size() * 2);
  for (auto &p : P) {
    while (!cw(H, 2, p)) H.pop_back();
    H.push_back(p);
  }
  size_t n = H.size() + 1;
  for (auto itr = ++P.rbegin(); itr != P.rend(); ++itr) {
    while (!cw(H, n, *itr)) H.pop_back();
    H.push_back(*itr);
  }
  H.pop_back();
  return H;
}

ld area(vpt &P) {
  ld res = 0;
  for (size_t i = 0; i < P.size() - 1; ++i) {
    res += P[i].x * P[i + 1].y;
  }
  res += P.back().x * P[0].y;
  for (size_t i = 0; i < P.size() - 1; ++i) {
    res -= P[i].y * P[i + 1].x;
  }
  res -= P.back().y * P[0].x;
  return abs(res) / 2;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vpt P(4 * n);
    ld board_area = 0;
    for (int i = 0; i < n; ++i) {
      ld x, y, w, h, v;
      cin >> x >> y >> w >> h >> v;
      board_area += w * h;
      update(P, i, x, y, w, h, v);
    }
    sort(P.begin(), P.end());
    auto end = unique(P.begin(), P.end());
    P.resize(end - P.begin());
    auto H = convex_hull(P);
    ld res = board_area / area(H) * 100.0 + 1e-8;
    int d = res;
    int d2 = res * 10.0;
    d2 -= 10 * d;
    cout << d << "." << d2 << " %" << endl;
  }
  return 0;
}
