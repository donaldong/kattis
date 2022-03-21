#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tup;
typedef vector<int> vi;
vector<tup> P;

bool cw(const vi &hull, int c) {
  if (hull.size() <= 1) return true;
  int b = hull.back(), a = hull[hull.size() - 2];
  int dx_ab = get<0>(P[b]) - get<0>(P[a]);
  int dy_ab = get<1>(P[b]) - get<1>(P[a]);
  int dx_ac = get<0>(P[c]) - get<0>(P[a]);
  int dy_ac = get<1>(P[c]) - get<1>(P[a]);
  return dx_ab * dy_ac - dy_ab * dx_ac < 0;
}

int dist(int a, int b) {
  int dx = get<0>(P[a]) - get<0>(P[b]);
  int dy = get<1>(P[a]) - get<1>(P[b]);
  return dx * dx + dy * dy;
}

int solve() {
  vi hull, hull2;
  int j;
  for (size_t i = 0; i < P.size(); ++i) {
    j = get<2>(P[i]);
    while (!cw(hull, j)) hull.pop_back();
    hull.push_back(j);
  }
  for (size_t i = P.size(); i--;) {
    j = get<2>(P[i]);
    while (!cw(hull2, j)) hull2.pop_back();
    hull2.push_back(j);
  }
  hull.insert(hull.end(), hull2.begin(), hull2.end());
  if (hull[0] == hull.back()) hull.pop_back();
  int max_dist = 0;
  for (size_t i = 0; i < hull.size(); ++i) {
    for (size_t j = i + 1; j < hull.size(); ++j) {
      max_dist = max(max_dist, dist(hull[i], hull[j]));
    }
  }
  return max_dist;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int c, x, y;
  cin >> c;
  P.resize(c);
  for (int i = 0; i < c; ++i) {
    cin >> x >> y;
    P[i] = make_tuple(x, -y, 0);
  }
  sort(P.begin(), P.end());
  auto end = unique(P.begin(), P.end());
  P.erase(end, P.end());
  for (size_t i = 0; i < P.size(); ++i) get<2>(P[i]) = i;
  printf("%.7lf\n", sqrt(solve()));
  return 0;
}
