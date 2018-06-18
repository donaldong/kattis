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

struct edge;

uint INF = 1 << 30;

struct node {
    vector<edge*> E;
    int w = INF;
};

struct edge {
    node *dest;
    int t0, p, d;
    edge() {}
    edge(node *dest, int t0, int p, int d) :
        dest(dest), t0(t0), p(p), d(d) {}
};

struct cmp {
    bool operator() (node *a, node *b) const {
        if (a->w != b->w) return a->w < b->w;
        return ull(a) < ull(b);
    }
};

void dijkstra(node *src) {
    src->w = 0;
    set<node*, cmp> Q;
    Q.insert(src);
    while (!Q.empty()) {
        auto cur = *Q.begin();
        Q.erase(Q.begin());
        for (auto e : cur->E) {
            uint nw = INF;
            if (e->t0 >= cur->w && !e->p) {
                nw = e->t0 + e->d;    
            } else if (e->p > 0) {
                nw = e->t0 + max(0, cur->w - e->t0) / e->p * e->p;
                if (nw < cur->w) nw += e->p;
                nw += e->d;
            }
            if (nw < e->dest->w) {
                auto itr = Q.find(e->dest);
                if (itr != Q.end()) Q.erase(e->dest);
                e->dest->w = nw;
                Q.insert(e->dest);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int N, M, Q, S;
        scan(N), scan(M), scan(Q), scan(S);
        if (!N) break;
        vector<node> nodes(N);
        while (M--) {
            int a, b, t0, p, d;
            scan(a), scan(b), scan(t0);
            scan(p); scan(d);
            nodes[a].E.pb(new edge(
                &nodes[b], t0, p, d
            ));
        }
        dijkstra(&nodes[S]);
        while (Q--) {
            int k;
            scan(k);
            if (nodes[k].w == INF) cout << "Impossible" << endl;
            else cout << nodes[k].w << endl;
        }
        cout << endl;
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
