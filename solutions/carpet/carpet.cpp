#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using vld = vector<ld>;
ld EPS = 1e-12;
ld TWO_PI = 2.0 * M_PI;

ld law_of_cosines(ld a, ld b, ld c) {
  ld res = acos((a * a + b * b - c * c) / (2.0 * a * b));
  if (res < 0) res += TWO_PI;
  return res;
}

ld angle(ld a, ld b, ld c, ld x) {
  return law_of_cosines(a, b, x)
       + law_of_cosines(a, c, x)
       + law_of_cosines(b, c, x);
}

ld heron(ld a) {
  ld s = 1.5 * a; ld d = s - a;
  return sqrt(s * d * d * d);
}

void debug(const vld &V) {
  for (ld v : V) cout << v << " ";
  cout << " + " << V[0] + V[1];
  cout << endl;
}

bool possible(const vld &sides, ld x) {
  for (int i = 0; i < 3; ++i) for (int j = i + 1; j < 3; ++j) {
    vld V = {sides[i], sides[j], x};
    sort(V.begin(), V.end());
    if (V[0] + V[1] < V[2] + EPS) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ld a, b, c;
  cin >> a >> b >> c;
  ld lo = 0, hi = a + b + c;
  while (lo + EPS < hi) {
    ld mid = (lo + hi) / 2;
    if (angle(a, b, c, mid) < TWO_PI) lo = mid;
    else hi = mid;
  }
  if (!possible({a, b, c}, lo)) printf("-1\n");
  else printf("%.4Lf\n", heron(lo));
  return 0;
}
