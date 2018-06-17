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

int fact(int n) {
    if (n == 0) return 1;
    int res = 1;
    rep(i, 2, n + 1) res *= i;
    return res;
}

ld solve(int r, int s) {
    ld res = r - 1;
    return res / s;
}

ld solve(ld p, int X, int Y) {
    ld t = pow(p, Y - X);
    p = 1.0 - p;
    rep(i, 0, X) t *= p;
    int k = fact(Y) / fact(X); 
    k /= fact(Y - X);
    return t * k;
}

bool good(int R, int S, int X, int Y, int W) {
    ld p = solve(R, S);
    ld t = 0;
    for (int i = X; i <= Y; ++i) t += solve(p, i, Y);
    t *= W;
    return t > 1.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    scan(T);
    while (T--) {
        int R, S, X, Y, W;
        scan(R); scan(S); scan(X);
        scan(Y); scan(W);
        cout << (good(R, S, X, Y, W) ? "yes" : "no") << endl;
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
