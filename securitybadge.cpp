/**
 *  @brief   Kattis - Security Badge 
 *  @author  Donald Dong (@donaldong)
 *  @date    02/14/2018
 *  
 *  + Graph
 *  + DFS
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
#define rep(i, s, e) for (size_t i = s, fe__ = e; i < fe__; ++i)

inline void scan(int&);
inline void scan(ll&);
inline void print(uint);
inline void print(ull);
inline void print(string&);

struct node;

struct edge {
    node *t;
    int lo, hi;
    bool f = false;
    edge() {}
    edge(node *t, int lo, int hi) :
        t(t), lo(lo), hi(hi) {}
};

struct node {
    vector<edge> edges;
};

node *TARGET;

bool dfs(edge *e, int lo, int hi) {
    if (e->t == TARGET) return true;
    e->f = true;
    for (auto &p : e->t->edges) {
        if (!p.f && p.lo <= lo && p.hi >= hi)
            if (dfs(&p, lo, hi)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    scan(n); scan(m); scan(k);
    int s, t;
    scan(s); scan(t);
    --s; --t;
    vector<node> N(n);
    vector<int> K(2 * m);
    while (m--) {
        int a, b, c, d;
        scan(a); scan(b); scan(c); scan(d);
        --a; --b;
        N[a].edges.push_back(edge(&N[b], c - 1, d));
        K[2 * m] = c - 1;
        K[2 * m + 1] = d;
    }
    TARGET = &N[t];
    edge source(&N[s], 2e9, -1);
    sort(K.begin(), K.end());
    uint res = 0;
    for (int i = 1; i < K.size(); ++i) {
        if (i != 1) for (auto &a : N) for (auto &p : a.edges) {
            p.f = false;
        }
        if (dfs(&source, K[i - 1], K[i])) res += K[i] - K[i - 1];
    }
    print(res);
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
