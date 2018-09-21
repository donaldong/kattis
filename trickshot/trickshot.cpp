#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct pt {
  ld x, y;
  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}
  pt operator-(pt &p) {
    return pt(x - p.x, y - p.y);
  }
};

pt move_back(pt &a, pt &dir, ld r) {
  ld theta = atan2(dir.y, dir.x);
  return pt(a.x - r * cos(theta), a.y - r * sin(theta));
}

void debug(pt &p, string s="") {
  cout << s << endl;
  printf(" [%.2Lf, %.2Lf] ", p.x, p.y);
  cout << endl;
}

ld to_deg(ld n) {
  ld res = n / M_PI * 180.0;
  if (res < 0) res += 360;
  return res;
}

bool possible(pt &A, pt &B, pt &C) {
  ld c = atan2(C.y, C.x);
  ld b = atan2(-B.y, -B.x);
  ld a = atan2(-A.y, -A.x);
  ld ba = a - b;
  ld cb = b - c;
  return abs(to_deg(ba) - to_deg(cb)) < 0.001;
}

int main() {
  pt A, B, C;
  ld w, l, h, r, a, d;
  cin >> w >> l >> r >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> h;
  pt L(0, l), R(w, l);
  pt CR = R - C, BL = L - B;
  pt contactCR = move_back(C, CR, 2 * r);
  pt dirA = contactCR - A;
  pt contactAQ = move_back(A, dirA, 2 * r);
  pt contactBL = move_back(B, BL, 2 * r);
  pt dirQ = contactBL - contactAQ;
  bool f = false;
  for (ld x = 0; x < w; x += 0.0005) {
    pt F(x, h);
    F = contactAQ - F;
    if (possible(F, dirA, dirQ)) {
      a = atan2(F.y, F.x);
      printf("%.2Lf %.2Lf\n", x, to_deg(a));
      f = true;
      break;
    }
  }
  if (!f) cout << "impossible" << endl;
  return 0;
}
