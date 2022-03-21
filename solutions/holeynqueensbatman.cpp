/**
 *  @brief   Kattis - Holey N-Queens (Batman) 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/06/2018
 *  
 *  + Backtracking
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
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

ll getkey(int r, int c) {
    ll res = r;
    res <<= 32;
    return res + c;
}

void solve(int y, int n, uint &count, vector<bool> &col, vector<bool> &d1, vector<bool> &d2, hset<ll> &s) {
    if (y == n) {
        ++count;
        return;
    }
    rep(x, 0, n) {
        int i = x + y, j = x - y + n - 1;
        if (col[x] && d1[i] && d2[j] && s.find(getkey(y, x)) == s.end()) {
            col[x] = d1[i] = d2[j] = false;
            solve(y + 1, n, count, col, d1, d2, s);
            col[x] = d1[i] = d2[j] = true;
        }
    }
}

uint solve(hset<ll> &s, int n) {
    vector<bool> col(n, true), d1(2 * n, true), d2(2 * n, true);
    uint count = 0;
    solve(0, n, count, col, d1, d2, s);
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int n, m;
        scan(n); scan(m);
        if (!n && !m) break;
        hset<ll> s;
        while (m--) {
            int r, c;
            scan(r); scan(c);
            s.insert(getkey(r, c));
        }
        print(solve(s, n)); putchar('\n');
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
