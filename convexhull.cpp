/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + TAG
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

typedef unsigned int uint;
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


struct point {
    int x, y;
};

int sq_dist(point *a, point *b) {
    int dx = a->x - b->x;
    int dy = a->y - b->y;
    return dx * dx + dy * dy;
}

int orient(point *p, point *q, point *r) {
    int val = (q->y - p->y) * (r->x - q->x) -
              (q->x - p->x) * (r->y - q->y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

void graham_scan(vector<point> &P) {
    int ymin = P[0].y, imin = 0;
    for (int i = 1; i < P.size(); ++i) {
        if (P[i].y < ymin || (P[i].y == ymin && P[i].x < P[imin].x)) {
            ymin = P[i].y;
            imin = i;
        }
    }
    swap(P[0], P[imin]);
    point *beg = &P[0];
    sort(&P[1], &P[P.size()], [beg](point &a, point &b) {
        int o = orient(beg, &a, &b);
        if (o == 0) return sq_dist(beg, &a) >= sq_dist(beg, &b);
        return o == 2;
    });
    int m = 1;
    for (int i = 1; i < P.size(); ++i) {
        while (i < P.size() - 1 && orient(beg, &P[i], &P[i + 1]) == 0) ++i;
        P[m++] = P[i];
    }
    if (m < 3) {
        cout << m << endl;
        for (int i = 0; i < m; ++i) {
            cout << P[i].x << " " << P[i].y << endl;
        }
        return;
    }
    vector<point*> S;
    S.push_back(beg); S.push_back(&P[1]); S.push_back(&P[2]);
    for (int i = 3; i < m; ++i) {
        while (orient(S[S.size() - 2], S.back(), &P[i]) != 2) S.pop_back();
        S.push_back(&P[i]);
    }
    cout << S.size() << endl;
    for (int i = 0; i < S.size(); ++i) {
        cout << S[i]->x << " " << S[i]->y << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (true) {
        scan(n);
        if (n == 0) break;
        vector<point> P(n);
        for (auto &p : P) {
            scan(p.x); scan(p.y);
        }
        graham_scan(P);
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
