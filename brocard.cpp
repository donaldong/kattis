/**
 *  @brief   Kattis - Brocard Point of a Triangle 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/03/2018
 *  
 *  + Geometry
 *  + Binary Search
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
inline void print(uint);
inline void print(ull);
inline void print(string&);

const ld precision = 1e-10;

struct point {
    ld x, y;
};

struct line {
    bool v;
    point a;
    ld k, b;
    line() {}
    line(point &a, point &b) {
        this->a = a;
        if (a.x == b.x) {
            v = true;
        } else {
            v = false;
            k = a.y - b.y;
            k /= a.x - b.x;
            this->b = a.y - k * a.x;
        }
    }
};

line rotate(point a, point b, ld alpha) {
    ld s = sin(alpha);
    ld c = cos(alpha);
    a.x -= b.x;
    a.y -= b.y;
    ld xnew = a.x * c - a.y * s;
    ld ynew = a.x * s + a.y * c;
    a.x = xnew + b.x;
    a.y = ynew + b.y;
    return line(a, b);
}

point intersect(line &a, line &b) {
    point p;
    if (a.v) {
        p.x = a.a.x;
        p.y = b.k * p.x + b.b;
    } else if (b.v) {
        p.x = b.a.x;
        p.y = a.k * p.x + a.b;
    } else {
        p.x = b.b - a.b;
        p.x /= a.k - b.k;
        p.y = p.x * a.k + a.b;
    }
    return p;
}

ld dist(point &a, point &b) {
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

ld angle(point &p2, point &p1, point &p3) {
    ld P12 = dist(p1, p2), P13 = dist(p1, p3), P23 = dist(p2, p3);
    return acos((P12 * P12 + P13 * P13 - P23 * P23) / (2 * P12 * P13));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        point A, B, C;
        cin >> k >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        ld lo = 0, hi = M_PI / 6;
        hi = min(angle(C, A, B), hi);
        hi = min(angle(A, B, C), hi);
        hi = min(angle(B, C, A), hi);
        point P;
        while (hi - lo > precision) {
            ld mid = (lo + hi) / 2;
            line AP = rotate(B, A, mid);
            line BP = rotate(C, B, mid);
            P = intersect(AP, BP);
            ld theta = angle(P, C, A);
            if (theta > mid) lo = mid;
            else hi = mid;
        }
        printf("%d %.6Lf %.6Lf\n", k, P.x, P.y);
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
