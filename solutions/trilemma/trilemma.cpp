#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
};

int dist_square(pt &a, pt &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

ld dist(pt &a, pt &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

ld solve(ld a2, ld b2, ld c2) {
  ld a = sqrt(a2);
  ld b = sqrt(b2);
  ld res = a2 + b2 - c2;
  res /= 2.0 * a * b;
  res = acos(res);
  if (res < 0) return res + 2.0 * M_PI;
  return res;
}

void output(vector<int> &D2, vector<ld> &A) {
  sort(D2.begin(), D2.end());
  sort(A.begin(), A.end());
  bool f = D2[0] == D2[1] || D2[1] == D2[2];
  bool right = D2[0] + D2[1] == D2[2];
  cout << (f? "isosceles" : "scalene") << " ";
  if (right) cout << "right";
  else if (A.back() < M_PI_2) cout << "acute";
  else cout << "obtuse";
  cout << " triangle" << endl;
}

int main() {
  int T;
  cin >> T;
  for (int j = 0; j < T; ++j) {
    cout << "Case #" << j + 1 << ": ";
    vector<pt> P(3);
    for (int i = 0; i < 3; ++i) cin >> P[i].x >> P[i].y;
    vector<ld> D(3);
    for (int i = 0; i < 3; ++i) D[i] = dist(P[(i + 1) % 3], P[(i + 2) % 3]);
    sort(D.begin(), D.end());
    if (D[0] + D[1] <= D[2] + 1e-9) {
      cout << "not a triangle" << endl;
      continue;
    }
    vector<int> D2(3);
    for (int i = 0; i < 3; ++i) D2[i] = dist_square(P[(i + 1) % 3], P[(i + 2) % 3]);
    vector<ld> A(3);
    for (int i = 0; i < 3; ++i) A[i] = solve(D2[(i + 1) % 3], D2[(i + 2) % 3], D2[i]);
    output(D2, A);
  }
  return 0;
}
