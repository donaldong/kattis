/**
 * @date        2023-01-17
 * @tags        geometry, convex hull
 * @difficulty  1750
 */
#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/geometry/convex-hull.html#monotone-chain-algorithm
struct pt { double x, y; };

int orientation(pt a, pt b, pt c) {
	double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
	if (v < 0) return -1; // clockwise
	if (v > 0) return +1; // counter-clockwise
	return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o < 0 || (include_collinear && o == 0);
}

bool ccw(pt a, pt b, pt c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);

}

double dist(pt& a, pt& b) {
	double dx = a.x-b.x, dy = a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    using point = pair<double,double>;
    double x,y;
		vector<pt> P;
    while (ss >> x >> y) P.push_back({x, y});
    double res = 100.0*P.size(), s = 0.0;
		convex_hull(P);
    for (int i = 0; i < P.size(); ++i) s += dist(P[i], P[(i+1)%P.size()]);
    printf("%.8lf\n", res/(1.0+s));
  }
  return 0;
}
