/**
 *  @brief   Kattis - Nature Reserve 
 *  @author  Donald Dong (@donaldong)
 *  @date    01/02/2018
 *  
 *  + Graph
 *  + Minimum Spanning Tree
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
inline void print(uint);
inline void print(ull);
inline void print(string&);

struct node {
    int r = 0;
    node *p = this;
    bool f = false;
};

struct edge {
    node *src, *dest;
    ll w;
    edge() {}
    edge(node *src, node *dest, ll w) : src(src), dest(dest), w(w) {}
};

node* find(node *n) {
    if (n->p != n)
        n->p = find(n->p);
    return n->p;
}

void u(node *a, node *b) {
    if (a->r > b->r) b->p = a;
    else if (a->r < b->r) a->p = b;
    else {
        b->p = a;
        ++a->r;
    }
}

ull mst(vector<edge*> &E) {
    ull res = 0;
    sort(E.begin(), E.end(), [](edge *a, edge *b) {
        return a->w < b->w;
    });
    for (auto e : E) {
        auto pa = find(e->src);
        auto pb = find(e->dest);
        if (pa != pb) {
            res += e->w;
            u(pa, pb);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    scan(T);
    while (T--) {
        int N, M, L, S;
        scan(N); scan(M); scan(L); scan(S);
        vector<node*> V(N);
        vector<edge*> E;
        vector<node*> vs(S);
        for (auto &n : V) n = new node;
        rep(i, 0, S) {
            int s;
            scan(s);
            vs[i] = V[s - 1];
            vs[i]->f = true;
        }
        rep(i, 1, S) {
            auto pa = find(vs[i - 1]);
            auto pb = find(vs[i]);
            if (pa != pb) u(pa, pb);
        }
        rep(i, 0, M) {
            int a, b, e;
            scan(a); scan(b); scan(e);
            node *pa = V[a - 1], *pb = V[b - 1];
            if (!pa->f || !pb->f) E.pb(new edge(pa, pb, e + L));
        }
        print(mst(E)); putchar('\n');
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
