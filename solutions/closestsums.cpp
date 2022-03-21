/**
 *  @brief   Kattis - Closest Sums 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/08/2018
 *  
 *  + Implementation
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int T = 1;
    while (cin >> n) {
        printf("Case %d:\n", T++);
        set<int> N, S;
        while (n--) {
            int e;
            cin >> e;
            N.insert(e);
        }
        for (auto i = N.begin(); i != N.end(); ++i) {
            auto j = i; ++j;
            for (; j != N.end(); ++j) {
                S.insert(*i + *j);
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int e;
            cin >> e;
            int diff = INT_MAX;
            int res = 0;
            auto beg = S.lower_bound(e);
            if (beg != S.begin()) --beg;
            auto end = S.upper_bound(e);
            if (end != S.end()) ++end;
            for (auto i = beg; i != end; ++i) {
                if (abs(*i - e) < diff) {
                    res = *i;
                    diff = abs(*i - e);
                }
            }
            printf("Closest sum to %d is %d.\n", e, res);
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
