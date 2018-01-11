/**
 *  @brief   Kattis - Crop Triangles (Easy) 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/10/2018
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

struct point {
    uint x = 0, y = 0;
    point() {}
    point(uint x, uint y) : x(x), y(y) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    rep(t, 1, T + 1) {
        int n, A, B, C, D, X, Y, M;
        cin >> n >> A >> B >> C >> D >> X >> Y >> M;
        vector<point> P(n);
        int x = X, y = Y;
        P[0] = point(x, y);
        rep(i, 1, n) {
            ull t = A;
            t *= x;
            t += B;
            x = t % M;
            t = C;
            t *= y;
            t += D;
            y = t % M;
            P[i] = point(x, y);
        }
        int res = 0;
        rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) {
            point p;
            p.x = P[i].x + P[j].x + P[k].x;
            p.y = P[i].y + P[j].y + P[k].y;
            if (p.x % 3 || p.y % 3) continue;
            ++res;
        }
        cout << "Case #" << t << ": " << res << endl;
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
