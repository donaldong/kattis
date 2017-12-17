/**
 *  @brief   Kattis - Bazen 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/25/2017
 *  
 *  + Geometry
 *  + Binary Search
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
    ld x, y;
    point() {}
    point(ld x, ld y) : x(x), y(y) {}
};

void print(point &p) {
    printf("%.2Lf %.2Lf\n", p.x, p.y);
}

struct line {
    point a, b;
    ld k;
    ld len;
    ld dx, dy;

    line() {}
    line(point &a, point &b) {
        this->a = a;
        this->b = b;
        dy = b.y - a.y;
        dx = b.x - a.x;
        k = dy / dx;
        len = sqrt(dy * dy + dx * dx);
    }
    
    point at(ld d) {
        if (!isinf(k)) {
            ld dd = sqrt(d * d / (1.0 + k * k));
            ld x = dd;
            ld y = abs(dd * k);
            if (dx < 0) x *= -1;
            if (dy < 0) y *= -1;
            x += a.x;
            y += a.y;
            return point(x, y);
        }
        return point(a.x, a.y + d);
    }
};

vector<vector<point>> split(point p) {
    vector<vector<point>> res;
    point A(0,0), B(0, 250), C(250, 0);
    if (p.x == 0) {
        res.push_back({C, B, p});
        res.push_back({C, A, p});
    } else if (p.y == 0) {
        res.push_back({B, A, p});
        res.push_back({B, C, p});
    } else {
        res.push_back({A, B, p});
        res.push_back({A, C, p});
    }
    return res;
}

ld area(vector<point> v) {
    return 0.5 * abs(v[0].x*v[1].y + v[1].x * v[2].y + v[2].x * v[0].y
        - v[1].x * v[0].y - v[2].x * v[1].y - v[0].x * v[2].y);
}

const ld D = 1e-3;

point search(vector<point> &t, ld A) {
    line l(t[0], t[1]);
    ld a = 0, b = l.len;
    point res;
    while (true) {
        ld c = (a + b) / 2.0;
        res = l.at(c);
        ld x = area({res, t[1], t[2]});
        ld diff = x - A;
        if (abs(diff) < D) break;
        if (diff > 0) a = c;
        else b = c;
    }
    return res;
}

int main() {
    ld A = 250 * 250 * 0.5;
    int x, y;
    cin >> x >> y;
    point res;
    if (x == 0 && y == 0) {
        res = point(125, 125);
    } else if (x == 0 && y == 250) {
        res = point(125, 0);
    } else if (x == 250 && y == 0) {
        res = point(0, 125);
    } else {
        auto t = split(point(x, y));
        if (area(t[0]) > area(t[1])) {
            res = search(t[0], A/2);
        } else {
            res = search(t[1], A/2);
        }
    }
    print(res);
    return 0;
}
