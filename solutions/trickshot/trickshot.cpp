#include <bits/stdc++.h>
using namespace std;

using ld = long double;
ld EPS = 1e-8;

struct pt {
  ld x, y;
  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}
  pt operator-(pt &p) { return pt(x - p.x, y - p.y); }
  ld arg() { return atan2(y, x); }
};

pt forward(pt &center, pt &dir, ld dis) {
  ld a = dir.arg();
  return pt(center.x + dis * cos(a), center.y + dis * sin(a));
}

ld fix(ld a) {
  ld two_pi = 2.0 * M_PI;
  while (a > two_pi) a -= two_pi;
  while (a < 0) a += two_pi;
  return a;
}

ld dot(pt &a, pt &b) { return a.x * b.x + a.y * b.y; }

ld dist(pt &a, pt &b) { return hypot(a.x - b.x, a.y - b.y); }

bool collide(pt &A, pt &B, ld r, pt &C) {
  pt AC = C - A, AB = B - A, P;
  ld dx = B.x - A.x, dy = B.y - A.y;
  ld proj = dot(AC, AB) / dot(AB, AB); 
  if (proj < 0) P = A;
  else if (proj > 1) P = B;
  else {
    P.x = A.x + proj * dx;
    P.y = A.y + proj * dy;
  } 
  return dist(C, P) < 2 * r - EPS;
}

int main() {
  pt A, B, C;
  ld w, l, h, r, a, d, theta, x;
  cin >> w >> l >> r >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> h;
  pt Bp(0, l), Cp(w, l);
  pt BpB = B - Bp, CpC = C - Cp;
  pt Qpp = forward(B, BpB, 2 * r), Ap = forward(C, CpC, 2 * r);
  pt ApA = A - Ap;
  pt Qp = forward(A, ApA, 2 * r);
  pt QpQpp = Qpp - Qp;
  x = ApA.arg(), a = QpQpp.arg();
  theta = x + x - a;
  pt Q((h - Qp.y) / tan(theta) + Qp.x, h);
  if (
    // Incident angle > 90 deg
    dot(ApA, CpC) < 0 ||
    dot(ApA, QpQpp) < 0 ||
    dot(BpB, QpQpp) > 0 ||
    // Out of bound
    Q.x < r || Q.x > w - r ||
    // Collide on path Q -> Qp
    collide(Q, Qp, r, B) || collide(Q, Qp, r, C)
  ) {
    printf("impossible\n");
  } else {
    theta = fix(theta) - M_PI;
    printf("%.2Lf %.2Lf\n", Q.x, theta / M_PI * 180.0);
  }
  return 0;
}
