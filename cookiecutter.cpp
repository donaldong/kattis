/**
 *  @brief   Kattis - Cookie Cutters 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/24/2017
 *  
 *  + Geometry
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define mp make_pair

struct point {
    ld x = 0.0, y = 0.0;  
    point() {}
    point(ld x, ld y) : x(x), y(y) {}
};

ld area(vector<point> &P) {
    ld res = 0.0;
    for (auto i = P.begin(); i + 1 != P.end(); ++i) {
        auto j = i + 1;
        res += i->x * j->y;
        res -= j->x * i->y;
    }
    res += P.back().x * P[0].y;
    res -= P.back().y * P[0].x;
    return res / 2.0; 
}

point centroid(vector<point> &P, ld a) {
    point p;
    for (auto i = P.begin(); i + 1 != P.end(); ++i) {
        auto j = i + 1;
        ld d = i->x * j->y - j->x * i->y;
        p.x += (i->x + j->x) * d;
        p.y += (i->y + j->y) * d;
    }
    ld d = P.back().x * P[0].y - P.back().y * P[0].x;
    p.x += (P.back().x + P[0].x) * d;
    p.y += (P.back().y + P[0].y) * d;
    d = 1.0 / 6.0 / a;
    p.x *= d;
    p.y *= d;
    return p;
}

void shift(vector<point> &P, ld x, ld y) {
    for (auto &p : P) {
        p.x += x;
        p.y += y;
    }
}

point scale(vector<point> &P, ld r) {
    P[0].x *= r;
    P[0].y *= r;
    ld x = P[0].x, y = P[0].y;
    for (size_t i = 1; i < P.size(); ++i) {
        P[i].x *= r;
        P[i].y *= r;
        x = min(x, P[i].x);
        y = min(y, P[i].y);
    }
    return point(x, y);
}

int main() {
    int n;
    cin >> n;
    vector<point> P(n);
    for (auto &p : P) {
        cin >> p.x >> p.y;
    }
    ld a = area(P);
    point c = centroid(P, a);
    shift(P, -c.x, -c.y);
    ld A;
    cin >> A;
    c = scale(P, sqrt(abs(A/a)));
    shift(P, -c.x, -c.y);
    for (auto p : P) {
        printf("%.6Lf %.6Lf\n", p.x, p.y);
    }
    return 0;
}
