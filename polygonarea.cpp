/**
 *  @brief   Kattis - Polygon Area 
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

bool cw(vector<point> &P) {
    ld res = 0.0;
    for (auto i = P.begin(); i + 1 != P.end(); ++i) {
        auto j = i + 1;
        res += (j->x - i->x) * (j->y + i->y);
    }
    res += (P[0].x - P.back().x) * (P[0].y + P.back().y);
    return res > 0;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<point> P(n);
        for (auto &p : P) {
            cin >> p.x >> p.y;
        }
        ld a = area(P);
        bool f = cw(P);
        if (f) cout << "CW ";
        else cout << "CCW ";
        printf("%.1Lf\n", abs(a));
    }
    return 0;
}
