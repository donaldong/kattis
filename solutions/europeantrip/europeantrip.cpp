#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct pt {
  ld x, y;
};

vector<pt> P(3);
vector<ld> D(3), A(3), C(3);

ld dist(pt &a, pt &b) {
  ld dx = a.x - b.x;
  ld dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

ld law_of_cosines(ld a, ld b, ld c) {
  return acos((a * a + b * b - c * c) / (2.0 * a * b));
}

void solve(ld &x, ld &y) {
  for (int i = 0; i < 3; ++i) if (A[i] > 2.0 / 3.0 * M_PI) {
    x = P[i].x;
    y = P[i].y;
    return;
  }
  ld sum = 0;
  for (int i = 0; i < 3; ++i) {
    C[i] = D[i] / cos(A[i] - M_PI / 6.0);
    sum += C[i];
  }
  x = 0;
  y = 0;
  for (int i = 0; i < 3; ++i) {
    x += P[i].x * C[i];
    y += P[i].y * C[i];
  }
  x /= sum;
  y /= sum;
}

int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> P[i].x >> P[i].y;
  }
  for (int i = 0; i < 3; ++i) D[i] = dist(P[(i + 1) % 3], P[(i + 2) % 3]);
  for (int i = 0; i < 3; ++i) A[i] = law_of_cosines(D[(i + 1) % 3], D[(i + 2) % 3], D[i]);
  ld x, y;
  solve(x, y);
  printf("%.5Lf %.5Lf\n", x, y);
  return 0;
}
