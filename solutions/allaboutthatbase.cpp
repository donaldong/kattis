/**
 *  @brief   Kattis - All about that base 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/10/2018
 *  
 *  + Base Conversion
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

uint MIN = 1;
uint MAX = -1;

int val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'a' + 10;
}

bool in_range(ull n) {
    return n >= MIN && n <= MAX;
}

bool unary(string &n) {
    for (char c : n) if (c != '1') return false;
    return true;
}

ull eval(ull x, ull y, char op) {
    ull res = 0;
    if (op == '+') res = x + y;
    else if (op == '-') {
        if (y > x) return -1;
        res = x - y;
    } else if (op == '*') res = x * y;
    else { 
        if (x % y) return -1;
        res = x / y;
    }
    return res;
}

char solve(string &A, string &B, string &C, char op, int base) {
    ull x = 0, y = 0, z = 0;
    for (char c : A) {
        int v = val(c);
        if (v >= base) return -1;
        x = base * x + val(c);
    }
    for (char c : B) {
        int v = val(c);
        if (v >= base) return -1;
        y = base * y + val(c);
    }
    for (char c : C) {
        int v = val(c);
        if (v >= base) return -1;
        z = base * z + val(c);
    }
    if (!in_range(x) || !in_range(y) || !in_range(z)) return -1;
    if (eval(x, y, op) != z) return -1;
    if (base <= 9) return '0' + base;
    if (base == 36) return '0';
    return 'a' + base - 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        char op, eq;
        cin >> a >> op >> b >> eq >> c;
        string res;
        if (unary(a) && unary(b) && unary(c)) {
            size_t x = a.size(), y = b.size(), z = c.size();
            if (eval(x, y, op) == z) res = "1";
        }
        rep(i, 2, 37) {
            char base = solve(a, b, c, op, i);
            if (base != -1) res += base;
        }
        if (res.empty()) cout << "invalid" << endl;
        else cout << res << endl;
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
