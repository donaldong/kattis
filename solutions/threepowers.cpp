/**
 *  @brief   Kattis - Three Powers 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/03/2018
 *  
 *  + Numbers
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
typedef unsigned __int128 ulll;
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define mp make_pair
#define putchar putchar_unlocked
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ull&);
inline void print(uint);
inline void print(ull);
inline void print(ulll);
inline void print(string&);

ulll p(int n, int e) {
    if (e == 0) return 1;
    ulll res = p(n, e / 2);
    if (e % 2 == 0) return res * res;
    return res * res * n;
}

vector<ulll> solve(ull n) {
    vector<ulll> res;
    int i = 0;
    while (n) {
        if (n & 1) res.pb(p(3, i));
        n >>= 1;
        ++i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        ull n;
        scan(n);
        if (n == 0) break;
        --n;
        putchar('{');putchar(' ');
        string comma = ", ";
        auto v = solve(n);
        if (v.size()) {
            rep(i, 0, v.size() - 1) {
                print(v[i]); print(comma);
            }
            print(v.back()); putchar(' ');
        }
        putchar('}');putchar('\n');
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

inline void scan(ull &number) {
    int c;
    number = 0;
    for (c = getchar(); (c>47 && c<58); c=getchar()) number = number *10 + c - 48;
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
