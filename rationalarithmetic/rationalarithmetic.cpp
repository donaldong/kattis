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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct num {
    ll a, b;
    num() {}
    num(ll x, ll y) {
        a = x;
        b = y;
        simplify();
    }
    void simplify() {
        if (b < 0) {
            b *= -1;
            a *= -1;
        }
        ll c = gcd(abs(a), b);
        a /= c;
        b /= c;
    }
};

num add(num &a, num &b) {
    ll x = a.a * b.b + b.a * a.b;
    ll y = a.b * b.b;
    return num(x, y);
}

num subtract(num &a, num &b) {
    ll x = a.a * b.b - b.a * a.b;
    ll y = a.b * b.b;
    return num(x, y);
}

num mul(num &a, num &b) {
    ll x = a.a * b.a;
    ll y = a.b * b.b;
    return num(x, y);
}

num div(num &a, num &b) {
    ll x = a.a * b.b;
    ll y = a.b * b.a;
    return num(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        int a1, b1, a2, b2;
        char op;
        cin >> a1 >> b1 >> op >> a2 >> b2;
        num x(a1, b1), y(a2, b2);
        num res;
        if (op == '+') {
            res = add(x, y);
        } else if (op == '-') {
            res = subtract(x, y);
        } else if (op == '*') {
            res = mul(x, y);
        } else {
            res = div(x, y);
        }
        cout << res.a << " / " << res.b << endl;
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
