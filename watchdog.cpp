/**
 *  @brief   Kattis - Watchdog 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/01/2017
 *  
 *  + Coordinate
 *  + Brute Force
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair

#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

struct point {
    int x, y;
};

bool solve(int S, vector<point> &P, int &x, int &y) {
    for (x = 1; x < S; ++x) for (y = 1; y < S; ++y) {
        bool f = true;
        for (auto &p : P) {
            if (p.x == x && p.y == y) {
                f = false;
                break;
            }
            int dx = p.x - x, dy = p.y - y;
            int rmax = min(x, y);
            rmax = min(rmax, min(S - x, S - y));
            if (dx * dx + dy * dy > rmax * rmax) {
                f = false;
                break;
            }
        }
        if (f) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        int S, H;
        cin >> S >> H;
        vector<point> P(H);
        for (auto &p : P) cin >> p.x >> p.y;
        int x, y;
        if (solve(S, P, x, y)) {
            cout << x << " " << y << endl;
        } else {
            cout << "poodle" << endl;
        }
    }
    return 0;
}
