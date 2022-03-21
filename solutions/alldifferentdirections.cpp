/**
 *  @brief   Kattis - All Different Directions 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/05/2018
 *  
 *  + Implementation
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
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

ld dist(ld x1, ld y1, ld x2, ld y2) {
    ld dx = x1 - x2;
    ld dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

struct coord {
    ld x, y;
    coord() {}
    coord(ld x, ld y) : x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (!n) break;
        ld avg_x = 0, avg_y = 0;
        vector<coord> V(n);
        cin.ignore();
        rep(i, 0, n) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            ld ox, oy, arg, cx, cy;
            ss >> ox >> oy;
            cx = ox; cy = oy;
            string cmd;
            ld dir;
            while (ss >> cmd >> arg) {
                if (cmd == "start") dir = arg;
                else if (cmd == "turn") dir += arg;
                else {
                    ld theta = dir / 180 * M_PI;
                    cx += cos(theta) * arg;
                    cy += sin(theta) * arg;
                }
            }
            avg_x += cx;
            avg_y += cy;
            V[i] = coord(cx, cy);
        }
        avg_x /= n;
        avg_y /= n;
        ld maxd = 0;
        for (auto &p : V) {
            ld newd = dist(p.x, p.y, avg_x, avg_y);
            maxd = max(maxd, newd);
        }
        printf("%.3Lf %.3Lf %.3Lf\n", avg_x, avg_y, maxd);
    }
    return 0;
}

inline void scan(int &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void scan(ll &number) {
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c=='-') {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
    if (negative) number *= -1;
}

inline void print(uint n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[11];
    int i = 10;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 10) putchar(buf[++i]);
}

inline void print(ull n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[20];
    int i = 19;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 19) putchar(buf[++i]);
}

inline void print(string &s) {
    rep(i, 0, s.length()) putchar(s[i]);
}
