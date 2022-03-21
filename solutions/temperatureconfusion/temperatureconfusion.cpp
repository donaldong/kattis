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
    return b == 0 ? a : gcd(b, a % b);
}

struct rat {
    ll p, q;
    rat() {}
    rat(ll a, ll b) {
        p = a;
        q = b;
        simplify();
    }
    void simplify() {
        if (q < 0) {
            q *= -1;
            p *= -1;
        }
        ll c = gcd(abs(p), q);
        p /= c;
        q /= c;
    }
    rat operator+(rat &r) {
        ll x = p * r.q + r.p * q;
        ll y = q * r.q;
        return rat(x, y);
    }
    rat operator-(rat &r) {
        ll x = p * r.q - r.p * q;
        ll y = q * r.q;
        return rat(x, y);
    }
    rat operator*(rat &r) {
        ll x = p * r.p;
        ll y = q * r.q;
        return rat(x, y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string line;
    cin >> line;
    int i = line.find('/');
    ll p = stoll(line.substr(0, i));
    line.erase(0, i + 1);
    ll q = stoll(line);
    rat a(32, 1), b(5, 9);
    rat res = (rat(p, q) - a) * b;
    cout << res.p << "/" << res.q << endl;
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
