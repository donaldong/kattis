/**
 *  @brief   Kattis - Subway Planning 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/19/2017
 *  
 *  + Coordinate plane
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
    ld theta, l;
};

bool possible(point &a, point &b, int d) {
    ld theta = abs(a.theta - b.theta);
    ld ta = asin(d / a.l);
    ld tb = asin(d / b.l);
    return theta <= ta + tb;
}

int solve(vector<point> &points, int d) {
    sort(points.begin(), points.end(), [](point a, point b) {
        return a.theta < b.theta;
    });
    int res = 0;
    int beg = 0, end = points.size() - 1;
    if (possible(points[0], points[points.size() - 1], d)) {
        res++;
        beg++;
    }
    for (int i = beg; i < end; i++) {
        if (possible(points[i], points[i+1], d)) {
            res++;
            i++;
            continue;
        } else {
            res++;
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, d;
        cin >> n >> d;
        vector<point> points(n);
        while (n--) {
            int x, y;
            cin >> y >> x;
            points[n].theta = atan2(y, x);
            if (points[n].theta < 0) points[n].theta += M_PI * 2;
            points[n].l = sqrt(x * x + y * y);
        }
        cout << solve(points, d) << endl;
    }
    return 0;
}
