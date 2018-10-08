#include <bits/stdc++.h>
using namespace std;

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
  pt operator-(const pt &p) {
    return pt(x - p.x, y - p.y);
  }
};

using vpt = vector<pt>;
using v2pt = vector<vpt>;
using ll = long long;

ll cross(pt &a, pt &b) {
  return a.x * b.y - b.x * a.y;
}

bool intersect(pt &A, pt &B, pt &C, pt &D) {
  pt AB = B - A, AC = C - A, AD = D - A; 
  return cross(AB, AC) * cross(AB, AD) < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s, t, a, b, c, d;
  cin >> s;
  v2pt streets(s);
  for (int i = 0; i < s; ++i) {
    cin >> a >> b >> c >> d;
    streets[i] = {pt(a, b), pt(c, d)};
  }
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    pt A(a, b), B(c, d);
    int count = 0;
    for (auto &street : streets) if (intersect(street[0], street[1], A, B)) ++count;
    cout << (count & 1 ? "different" : "same") << endl;
  }
  return 0;
}

