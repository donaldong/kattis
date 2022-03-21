/**
 *  @brief   Kattis - Cutting Cheese 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/20/2017
 *  
 *  + Floating Point Numbers
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

ld getV(ld r) {
    return 4.0 / 3.0 * M_PI * r * r * r;
}

ld getV(ld r, ld h) {
    return M_PI * h * h / 3.0 * (3 * r - h);
}

struct hole {
    ld r, x, y, z;
    ld v;
    ld left, right;
    hole() {}
    hole(ld r, ld x, ld y, ld z) :
        r(r), x(x), y(y), z(z) {
        v = getV(r);
        left = z - r;
        right = z + r;
    }
};

map<ld, vector<hole*>> H;
const ld D = 1e-7;

ld calc(ld a, ld b) {
    ld res = 0.0;
    for (auto itr = H.lower_bound(a); itr != H.end(); itr++) {
        for (auto h : itr->second) {
            if (h->left > b + D) continue;
            bool left = a > h->left && a < h->right;
            bool right = b > h->left && b < h->right;
            if (!left && !right) {
                res += h->v;    
            } else if (left && right) {
                res += h->v - getV(h->r, h->right - b) - getV(h->r, a - h->left);
            } else if (right) {
                res += getV(h->r, b - h->left);
            } else {
                res += getV(h->r, h->right - a);
            }
        }
    }
    return res;
}

ld solve(ld v, ld a, ld beg, ld end) {
    ld b = (beg + end) / 2;
    if (abs(end - beg) < D) return b;
    ld hole = calc(a, b);
    ld diff = v - ((b - a) * 100 * 100 - hole);
    if (abs(diff) < D) return b;
    if (diff < 0) return solve(v, a, beg, b);
    return solve(v, a, b, end);
}

ld solve(ld v, ld z) {
    return solve(v, z, z, 100.0);
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<hole> holes(n);
    ld V = 1e6;
    for (int i = 0; i < n; i++) {
        int r, x, y, z;
        cin >> r >> x >> y >> z;
        holes[i] = hole(r/1000.0, x/1000.0, y/1000.0, z/1000.0);
        V -= holes[i].v;
        H[holes[i].right].push_back(&holes[i]);
    }
    ld z = 0.0;
    ld v = V / s;
    while (s--) {
        ld res =  solve(v, z);
        printf("%.7Lf\n", res - z);
        z = res;
    }
    return 0;
}
