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

int n, m, k;

int at(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return -1;
    return r * m + c;
}

int DR[3] = {-1, 0, -1};
int DC[3] = {0, -1, -1};

bool possible(vector<bool> &v, bool f) {
    int r = v.size() / m;
    int c = v.size() % m;
    int plus = 0, minus = 0;
    for (int i = 0; i < 3; ++i) {
        int j = at(r + DR[i], c + DC[i]);
        if (j < 0) return true;
        if (v[j]) ++plus;
        else ++minus;
    }
    if (plus + 1 ==  minus && f) return true;
    if (plus == minus + 1 && !f) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //scan(n); scan(m);
    for (int i = 2; i <= 10; ++i) for (int j = 2; j <= 10; ++j) {
    vector<vector<bool>> G;
    n = i; m = j;
    ull size = n * m;
    G.pb({true});
    G.pb({false});
    while (G[0].size() != size) {
        int j = G.size();
        for (int i = 0; i < j; ++i) {
            auto v = G[i];
            if (possible(v, true)) {
                G.pb(v);
                G.back().pb(true);
            }
            if (possible(v, false)) {
                G.pb(v);
                G.back().pb(false);
            }
        }
        G.erase(G.begin(), G.begin() + j);
    }
    cout << i << " " << j << " ";
    cout << G.size() << endl;
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
