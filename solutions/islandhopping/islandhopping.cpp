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

struct pt {
    ld x, y;
    int r;
    pt *p;
};

struct edge {
    int a, b;
    ld len;
};

ld dist(pt &a, pt &b) { 
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

pt* find(pt *n) {
    if (n->p != n)
        n->p = find(n->p);
    return n->p;
}

void _union(pt *a, pt *b) {
    if (a->r > b->r) {
        b->p = a;
    } else if (a->r < b->r) {
        a->p = b;
    } else {
        b->p = a;
        ++a->r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pt> P(N);
        rep(i, 0, N) {
            cin >> P[i].x >> P[i].y; 
            P[i].r = 0;
            P[i].p = &P[i];
        }
        vector<edge> E(N * (N - 1) / 2);
        int k = 0;
        rep(i, 0, N) rep(j, 0, i) {
            E[k].a = i; E[k].b = j;
            E[k++].len = dist(P[i], P[j]);
        }
        sort(E.begin(), E.end(), [](edge &a, edge &b) {
            return a.len < b.len;
        });
        ld res = 0;
        for (auto e : E) {
            auto ra = find(&P[e.a]);
            auto rb = find(&P[e.b]);
            if (ra == rb) continue;
            _union(ra, rb);
            res += e.len;
        }
        printf("%.4Lf\n", res);
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
