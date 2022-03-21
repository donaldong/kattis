/**
 *  @brief   Kattis - NAME 
 *  @author  Donald Dong (@donaldong)
 *  @date    MM/DD/YYYY
 *  
 *  + Shortest Path
 *  + Dijkstra
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

struct node;

struct edge {
    node *dist;
    int w;
    edge() {}
    edge(node *dist, int w) : dist(dist), w(w) {}
};

struct node {
    int i;
    bool f = false;
    vector<edge*> E;
    uint w = -1;
    uint items = 0;
    node() {}
};

void solve(node *n) {
    set<pair<uint, node*>> Q;
    Q.insert(mp(0, n));
    n->f = true;
    n->items = n->i;
    n->w = 0;
    while (!Q.empty()) {
        auto itr = Q.begin();
        Q.erase(itr);
        auto cur = itr->second;
        for (auto e : cur->E) {
            auto next = e->dist;
            auto w = cur->w + e->w;
            if (next->w > w) {
                auto i = Q.find(mp(next->w, next));
                if (i != Q.end()) {
                    Q.erase(i);
                    Q.insert(mp(w, next));
                }
                next->w = w;
                next->items = next->i + cur->items;
            } else if (next->w == w) {
                next->items = max(next->i + cur->items, next->items);
            }
            if (!next->f) {
                Q.insert(mp(next->w, next));
                next->f = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    scan(N);
    vector<node> V(N);
    for (auto &n : V) scan(n.i);
    scan(M);
    while (M--) {
        int a, b, d;
        scan(a); scan(b); scan(d);
        --a; --b;
        V[a].E.pb(new edge(&V[b], d));
        V[b].E.pb(new edge(&V[a], d));
    }
    solve(&V[0]);
    if (V.back().w == -1) cout << "impossible" << endl;
    else cout << V.back().w << " " << V.back().items << endl;
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
