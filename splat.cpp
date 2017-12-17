/**
 *  @brief   Kattis - Splat 
 *  @author  Donald Dong (@donaldong)
 *  @date    12/14/2017
 *  
 *  + Floating Point Numbers
 *  + Limited Precision
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

struct drop {
    drop() {}
    drop(string color, int x, int y, int r) : color(color), x(x), y(y), r(r) {}
    string color;
    int x, y, r;
};

#define PRECISION 1000

bool in(int x1, int y1, int x2, int y2, ll r) {
      ll d1 = x1 - x2;
      ll d2 = y1 - y2;
      return d1 * d1 + d2 * d2 <= r * r;
}

string getcolor(int x, int y, vector<drop> &drops) {
    for (auto d = drops.rbegin(); d != drops.rend(); d++) {
        if (in(x, y, d->x, d->y, d->r)) return d->color;
    }
    return "white";
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<drop> drops(n);
        for (auto &d : drops) {
            ld x, y, v;
            cin >> x >> y >> v >> d.color;
            d.x = x * PRECISION;
            d.y = y * PRECISION;
            d.r = sqrt(v / M_PI) * PRECISION;
        }
        int m;
        cin >> m;
        while (m--) {
            ld x, y;
            cin >> x >> y;
            cout << getcolor(x * PRECISION, y * PRECISION, drops) << endl;
        }
    }
    return 0;
}
