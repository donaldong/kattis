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
    if (abs(x - p.x) < DELTA) return y < p.y;
		return x < p.x;
  }
  bool operator==(const pt & p) {
    return abs(x - p.x) < DELTA && abs(y - p.y) < DELTA;
  }
  pt operator-(const pt &p) {
    return pt(x - p.x, y - p.y);
  }
};

pt rotate(pt p, pt &o, ld v) {
  pt op = p - o;
  ld d = sqrt(op.x * op.x + op.y * op.y);
  ld a = v - atan2(op.y, op.x);
  return pt(cos(a) * d + o.x, sin(a) * d + o.y);
}

void update(vpt &P, int i, ld x, ld y, ld w, ld h, ld v) {
  w /= 2;
  h /= 2;
  v = v / 90.0 * M_PI_2;
  pt o(x, y);
  P[4 * i] = rotate(pt(x + w, y + h), o, v);
  P[4 * i + 1] = rotate(pt(x - w, y - h), o, v);
  P[4 * i + 2] = rotate(pt(x + w, y - h), o, v);
  P[4 * i + 3] = rotate(pt(x - w, y + h), o, v);
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
  return H;
}

ld area(vpt &P) {
  ld res = 0;
  size_t size = P.size();
  for (size_t i = 0, j = 1; i < size; i++, j = (i + 1) % size) {
      res += (P[i].x * P[j].y) - (P[i].y * P[j].x);
  }
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
    ld res = board_area / area(H) * 100.0;
    int print = int((res * 10) + 0.50001);
    cout << fixed;
    cout.precision(1);
    cout << ld(print)/10 << " %" << endl;
  }
  return 0;
}
