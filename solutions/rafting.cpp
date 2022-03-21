/**
 *  @brief   Kattis - White Water Rafting 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/23/2018
 *  
 *  + Geometry
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
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

struct vec;
ld dot(vec&, vec&);

struct point {
    ld x, y;
};

struct vec {
    point a, b;
    ld x, y, l;
    vec() {}
    vec(point &a, point &b) : a(a), b(b) {
        x = b.x - a.x;
        y = b.y - a.y;
        l = sqrt(dot(*this, *this));   
    }
};

ld dot(vec &a, vec &b) {
    return a.x * b.x + a.y * b.y;
}

ld dist(point &p, vec &AB) {
    vec AP = vec(AB.a, p), BP = vec(AB.b, p);
    ld s = dot(AP, AB);
    if (s < 0) return AP.l;
    // BP * BA < 0
    if (dot(BP, AB) > 0) return BP.l;
    vec proj = AB, orth = AP;
    ld k = s / AB.l / AB.l;
    proj.x *= k; proj.y *= k;
    orth.x -= proj.x; orth.y -= proj.y;
    return sqrt(dot(orth, orth));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<point> A(n);
        for (point &a : A) {
            cin >> a.x >> a.y;
        }
        cin >> n;
        point p;
        cin >> p.x >> p.y;
        vector<vec> L(n);
        rep(i, 0, n - 1) {
            point t;
            cin >> t.x >> t.y;
            L[i] = vec(p, t);
            p = t;
        }
        L[L.size() - 1] = vec(p, L[0].a);
        ld res = 1e15;
        for (point &a : A) {
            for (vec &l : L) {
                res = min(res, dist(a, l));
            }
        }
        printf("%.7Lf\n", res / 2);
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
