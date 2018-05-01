/**
 *  @brief   Kattis - Robot Protection 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Convex Hull
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
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    bool operator< (const pt &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
    bool operator== (const pt &p) const {
        return x == p.x && y == p.y;
    }
};

bool cw(const pt &a, const pt &b, const pt &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}

vector<pt> convex_hull(vector<pt> &p) {
    int n = p.size();
    if (n <= 1) return p;
    int k = 0;
    vector<pt> q(n * 2);
    for (int i = 0; i < n; q[k++] = p[i++])
        for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k);
    for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
        for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k);
    q.resize(k - 1 - (q[0] == q[1]));
    return q;
}

ld area(vector<pt> &H) {
    ll res = 0;
    rep(i, 0, H.size() - 1) res += H[i].x * H[i + 1].y;
    res += H.back().x * H[0].y;
    rep(i, 1, H.size()) res -= H[i].x * H[i - 1].y;
    res -= H[0].x * H.back().y;
    ld r = res;
    return abs(r) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int n;
        scan(n);
        if (!n) break;
        vector<pt> P(n);
        rep(i, 0, n) {
            scan(P[i].x);
            scan(P[i].y);
        }
        sort(P.begin(), P.end());
        auto end = unique(P.begin(), P.end());
        P.resize(distance(P.begin(), end));
        auto H = convex_hull(P); 
        cout << area(H) << endl;
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
