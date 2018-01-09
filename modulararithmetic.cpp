/**
 *  @brief   Kattis - Modular Arithmetic 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/04/2018
 *  
 *  + Numbers
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
typedef __int128 lll;
typedef unsigned __int128 ulll;
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
inline void scan(lll&);
inline void print(uint);
inline void print(ull);
inline void print(ulll);
inline void print(string&);

lll gcd(lll a, lll b) {
    return b == 0 ? a : gcd(b, a % b);
}

lll gcd_ext(lll a, lll b, lll &x, lll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lll x1, y1;
    lll gcd = gcd_ext(b, a % b, x1, y1);
    y = x1 - a / b * y1;
    x = y1;
    return gcd;
}

bool solve(lll c, lll a, lll b, lll &x) {
    lll y;
    lll r = gcd_ext(a, b, x, y);
    if (c % r) return false;
    r = c / r; x *= r; y *= r;
    if (x >= b) {
        ll k = x / b;
        x -= b * k;
        y += a * k;
    } else if (x < 0) {
        ll k = -x / b;
        if ((-x) % b) ++k;
        x += b * k;
        y -= a * k;
    }
    return true;
}

bool solve(lll n, lll a, lll b, char op, lll &x) {
    if (op == '+') {
        x = a + b; x %= n;
        return true;
    }
    if (op == '-') {
        x = a - b; x %= n;
        if (x < 0) x += n;
        return true;
    }
    if (op == '*') {
        x = (a * b) % n;
        return true;
    }
    if (!b) return false;
    ll r = gcd(a, b);
    r = gcd(r, n);
    if (!r) return false;
    a /= r; b /= r; n /= r;
    return solve(a, b, n, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string neg1 = "-1\n";
    while (true) {
        ll n, t;
        scan(n); scan(t);
        if (!n && !t) break;
        while (t--) {
            lll a, b; char op;
            scan(a); op = getchar(); getchar(); scan(b);
            lll x;
            if (solve(n, a, b, op, x)) { print((ulll)x); putchar('\n'); }
            else print(neg1);
        }
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

inline void scan(lll &number) {
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

inline void print(ulll n) {
    if (n == 0) {
        putchar('0');
        return;
    }
    char buf[39];
    int i = 38;
    while (n) {
        buf[i--] = n % 10 + '0';
        n /= 10;
    }
    while (i < 38) putchar(buf[++i]);
}

inline void print(string &s) {
    rep(i, 0, s.length()) putchar(s[i]);
}
