/**
 *  @brief   Kattis - Carousel Rides 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/03/2018
 *  
 *  + Greedy
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

struct offer {
    int t, p;
    ld r;
    offer() {}
    offer(int t, int p) : t(t), p(p) {
        r = p; r /= t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (true) {
        scan(n); scan(m);
        if (!n && !m) break;
        vector<offer> V;
        rep(i, 0, n) {
            int t, p;
            scan(t); scan(p);
            if (m / t) V.pb(offer(t, p));
        }
        sort(V.begin(), V.end(), [](offer &a, offer &b) {
            ld diff = abs(a.r - b.r);
            if (diff > 1e-9) return a.r < b.r;
            return a.t > b.t;
        });
        string s = "No suitable tickets offered\n";
        if (!V.size()) print(s);
        else printf("Buy %d tickets for $%d\n", V[0].t, V[0].p);
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
