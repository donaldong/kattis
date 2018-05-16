/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + DP
 *  + Memoization
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

struct state {
    ll a = 1e9, b = 0;
    state() {}
    state(ll a, ll b) : a(a), b(b) {}
};

ll get_key(int a, int b) {
    ll res = a;
    res <<= 32;
    return res + b;
}

hmap<ll, state> M;

state solve(vector<vector<int>> &G, int i, int m) {
    if (m == 0) return state(0, 0);
    ll key = get_key(i, m);
    if (M.find(key) != M.end()) return M[key];
    state s;
    rep(j, 0, G.size()) {
        auto p = solve(G, j, m - 1);
        s.a = min(s.a, p.a + G[i][j]);
        s.b = max(s.b, p.b + G[i][j]);
    }
    M[key] = s;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (true) {
        scan(n);
        if (!n) break;
        M.clear();
        vector<vector<int>> G(n, vector<int>(n));
        rep(i, 0, n) rep(j, 0, n) {
            scan(G[i][j]);
        }
        int m;
        scan(m);
        auto p = solve(G, 0, m);
        cout << p.b << " " << p.a << endl;
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
