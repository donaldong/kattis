#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pt {
  ll x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
  bool operator<(const pt &p) {
    if (p.x == x) return y < p.y;
    return x < p.x;
  }
  bool operator==(const pt &p) {
    return x == p.x && y == p.y;
  }
  pt operator-(const pt &p) {
    return pt(x - p.x, y - p.y);
  }
};

using vpt = vector<pt>;

ll cross(pt &a, pt &b) {
  return a.x * b.y - b.x * a.y;
}

bool cw(vpt &P, size_t n, pt &c) {
  if (P.size() < n) return true;
  int k = P.size();
  pt a = P[k - 2], b = P[k - 1];
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
  int n = H.size() + 1;
  for (auto itr = ++P.rbegin(); itr != P.rend(); ++itr) {
    while (!cw(H, n, *itr)) H.pop_back();
    H.push_back(*itr);
  }
  H.pop_back();
  if (H[0] == H[1]) H.pop_back();
  return H;
}

int main() {
  int N;
  while (cin >> N) {
    if (!N) break;
    vpt P(N);
    for (auto &p : P) cin >> p.x >> p.y;
    sort(P.begin(), P.end());
    auto end = unique(P.begin(), P.end());
    P.resize(end - P.begin());
    auto H = convex_hull(P);
    cout << H.size() << endl;
    for (auto p = H.rbegin(); p != H.rend(); ++p) cout << p->x << " " << p->y << endl;
  }
  return 0;
}
