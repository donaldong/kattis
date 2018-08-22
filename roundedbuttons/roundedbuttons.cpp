#include <bits/stdc++.h>
using namespace std;

using ld = long double;

ld X, Y, W, H, R;
ld DELTA = 1e-10;
vector<tuple<ld, ld>> C(4);

ld dist(tuple<ld, ld> &t, ld x, ld y) {
  ld a, b;
  tie(a, b) = t;
  ld dx = a - x;
  ld dy = b - y;
  return sqrt(dx * dx + dy * dy);
}

bool in_range(ld x, vector<ld> V) {
  return V[0] - DELTA < x && x < V[1] + DELTA;
}

bool inside(ld x, ld y) {
  if (in_range(x, {X + R, X + W - H}) &&
      in_range(y, {Y, Y + H})) return true;
  if (in_range(x, {X, X + W}) &&
      in_range(y, {Y + R, Y + H - R})) return true;
  vector<ld> D(4);
  for (int i = 0; i < 4; ++i) D[i] = dist(C[i], x, y);
  return any_of(D.begin(), D.end(), [](ld d) {
    return d < R + DELTA;
  });
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> X >> Y >> W >> H >> R;
    C[0] = make_tuple(X + R, Y + R);
    C[1] = make_tuple(X + W - R, Y + R);
    C[2] = make_tuple(X + W - R, Y + H - R);
    C[3] = make_tuple(X + R, Y + H - R);
    int m;
    cin >> m;
    while (m--) {
      ld x, y;
      cin >> x >> y;
      cout << (inside(x, y) ? "inside" : "outside") << endl;
    }
    cout << endl;
  }
  return 0;
}
